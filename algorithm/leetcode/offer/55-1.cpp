#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// question :

class mySolution_55_1
{
    public:
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};

class offerSolution_55_1
{
    public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};