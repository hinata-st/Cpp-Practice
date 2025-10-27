#include <bits/stdc++.h>

using namespace std;

// question : 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class mySolution_32_1
{
    public:
    vector<int> levelOrder(TreeNode* root)
    {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return res;
    }
};

class offerSolution_32_1
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> q{{root}};
        while (!q.empty())
        {
            for (int n = q.size(); n; --n)
            {
                auto node = q.front();
                q.pop();
                ans.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};