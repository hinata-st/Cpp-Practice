#include <bits/stdc++.h>

using namespace std;

// question : 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class mySolution_32_2
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

class offerSolution_32_2
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q{{root}};
        while (!q.empty())
        {
            vector<int> t;
            for (int n = q.size(); n; --n)
            {
                auto node = q.front();
                q.pop();
                t.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
