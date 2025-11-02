#include <bits/stdc++.h>

using namespace std;

// question : 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 3241423    3241423

class mySolution_28
{
    public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        vector<int> rightTree;
        vector<int> leftTree;
        function<void(TreeNode *, vector<int> &, int)> preOrder = [&](TreeNode *node, vector<int> &res, int side) {
            if (node == nullptr)
            {
                res.push_back(-101);
                return;
            }
            if(side == 0) // left
            {
                preOrder(node->left, res, 0);
                res.push_back(node->val);
                preOrder(node->right, res, 0);
            }
            else // right
            {
                preOrder(node->right, res, 1);
                res.push_back(node->val);
                preOrder(node->left, res, 1);
            }
        };
        preOrder(root->left, leftTree, 0);
        preOrder(root->right, rightTree, 1);
        for (int i = 0; i < leftTree.size(); i++)
        {
            if (leftTree[i] != rightTree[i])
            {
                return false;
            }
        }
        return true;
    }
};

class offerSolution_28
{
public:
    bool isSymmetric(TreeNode *root)
    {
        function<bool(TreeNode *, TreeNode *)> dfs = [&](TreeNode *a, TreeNode *b) -> bool
        {
            if (!a && !b)
            {
                return true;
            }
            if (!a || !b || a->val != b->val)
            {
                return false;
            }
            return dfs(a->left, b->right) && dfs(a->right, b->left);
        };
        return dfs(root, root);
    }
};

class mySolution_28_2
{
    public:
        bool isSymmetric(TreeNode *root) {
            function<bool(TreeNode *, TreeNode *)> isMirror = [&](TreeNode *t1, TreeNode *t2) -> bool
            {
                if (!t1 && !t2)
                {
                    return true;
                }
                if ((!t1 || !t2) || (t1->val != t2->val))
                {
                    return false;
                }
                return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
            };
            return isMirror(root, root);
        }
};