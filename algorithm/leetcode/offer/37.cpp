#include <bits/stdc++.h>

using namespace std;

// question : 请实现两个函数，分别用来序列化和反序列化二叉树。你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

    struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};  

class mySolution_37
{
    public:
    string TreetoSequence(TreeNode* root)
    {
        if(root == nullptr)
            return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node != nullptr)
            {
                res += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                res += "# ";
            }
        }
        res.pop_back();
        return res;
    }

    vector<int> stringToVector(const string &data)
    {
        vector<int> res;
        stringstream ss(data);
        string t;
        while(ss >> t)
        {
            if(t == "#")
            {
                res.push_back(INT_MAX);
            }
            else
            {
                res.push_back(stoi(t));
            }
        }
        return res;
    }


    // 0 1 2 3 4 5 6 root : n , left : 2n+1 , right : 2n+2
    TreeNode* SequencetoTree(string &data)
    {
        if (data.empty())
            return nullptr;
        vector<int> data_vec = stringToVector(data);
        TreeNode* root = new TreeNode(data_vec[0]);
        function<void(TreeNode *, int)> buildTree = [&](TreeNode *node, int root_index)
        {
            if (data_vec[2 * root_index + 1] == INT_MAX)
            {
                node->left = nullptr;
            }
            else
            {
                node->left = new TreeNode(data_vec[2 * root_index + 1]);
                buildTree(node->left, 2 * root_index + 1);
            }

            if (data_vec[2 * root_index + 2] == INT_MAX)
            {
                node->right = nullptr;
            }
            else
            {
                node->right = new TreeNode(data_vec[2 * root_index + 2]);
                buildTree(node->right, 2 * root_index + 2);
            }
        };
        buildTree(root, 0);
        return root;
    }
};

class offerSolution_37
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        queue<TreeNode *> q{{root}};
        string ans;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node)
            {
                ans += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                ans += "# ";
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
        {
            return nullptr;
        }
        stringstream ss(data);
        string t;
        ss >> t;
        TreeNode *root = new TreeNode(stoi(t));
        queue<TreeNode *> q{{root}};
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            ss >> t;
            if (t != "#")
            {
                node->left = new TreeNode(stoi(t));
                q.push(node->left);
            }
            ss >> t;
            if (t != "#")
            {
                node->right = new TreeNode(stoi(t));
                q.push(node->right);
            }
        }
        return root;
    }
};