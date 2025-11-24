#include <bits/stdc++.h>

using namespace std;

// question : 

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class mySolution_54
{
    public:
    int kthlargest(TreeNode* root, int k) 
    {
        vector<int> vec;
        inOrder(root, vec);
        return vec[vec.size() - k];
    }
    void inOrder(TreeNode* root, vector<int>& vec)
    {
        if(root == nullptr)
        {
            return;
        }
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
};

class Solution
{
public:
    int kthLargest(TreeNode *root, int k)
    {
        int ans = 0;
        function<void(TreeNode *)> dfs = [&](TreeNode *root)
        {
            if (!root || !k)
            {
                return;
            }
            dfs(root->right);
            if (--k == 0)
            {
                ans = root->val;
            }
            dfs(root->left);
        };
        dfs(root);
        return ans;
    }
};

class offerSolution_54 {
public:
    int kthLargest(TreeNode* root, int k) {
        int ans = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root || !k) {
                return;
            }
            dfs(root->right);
            if (--k == 0) {
                ans = root->val;
            }
            dfs(root->left);
        };
        dfs(root);
        return ans;
    }
};
