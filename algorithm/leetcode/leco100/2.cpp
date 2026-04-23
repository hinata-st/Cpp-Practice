#include <bits/stdc++.h>

using namespace std;

// question : 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }
        swap(root->right, root->left);
        invertTree(root->right);
        invertTree(root->left);
        return root;
    }
};