#include <bits/stdc++.h>

using namespace std;

// question : 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class mySolution_27
{
    public:
    TreeNode* mirrorTree(TreeNode* root)
    {
        if(!root)
        {
            return root;
        }
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
