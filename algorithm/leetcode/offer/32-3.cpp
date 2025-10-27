#include <bits/stdc++.h>
using namespace std;

// question : 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class mySolution_32_3
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            vector<int> level;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if( leftToRight )
                {
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                else
                {
                    if (node->right)
                        q.push(node->right);
                    if (node->left)
                        q.push(node->left);
                }
            }
            res.push_back(level);
            leftToRight = !leftToRight;
        }
        return res;
    }
};

class offerSolution_32_3
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
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
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            if (ans.size() & 1)
            {
                reverse(t.begin(), t.end());
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};