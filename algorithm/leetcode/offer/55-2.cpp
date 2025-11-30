#include <bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

// question :输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

class mySolution_55_2
{
    public:
    int depth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left_depth = depth(root->left);
        if (left_depth == -1)
        {
            return -1;
        }
        int right_depth = depth(root->right);
        if (right_depth == -1)
        {
            return -1;
        }
        if (abs(left_depth - right_depth) > 1)
        {
            return -1;
        }
        return max(left_depth, right_depth) + 1;
    }
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return depth(root) != -1;
    }
};

class offerSolution_55_2
{
public:
    bool isBalanced(TreeNode *root)
    {
        function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int
        {
            if (!root)
            {
                return 0;
            }
            int l = dfs(root->left);
            int r = dfs(root->right);
            if (l == -1 || r == -1 || abs(l - r) > 1)
            {
                return -1;
            }
            return 1 + max(l, r);
        };
        return dfs(root) != -1;
    }
};

class mySolutoin_55_2_2
{
    public:
    bool isBalanced(TreeNode* root)
    {
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int 
        {
            if(!root)
            {
                return 0;
            }
            int l = dfs(node->left);
            int r = dfs(node->right);   
            if(l == -1 || r == -1 || abs(l - r) > 1)
            {
                return -1;
            }
            return 1 + max(l, r);
        };
        return dfs(root) != -1;
    }
};