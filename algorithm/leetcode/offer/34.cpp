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

class mySolution_34
{
    public:
    vector<vector<int>> pathInTree(TreeNode* root, int target)
    {
        vector<int> path;
        vector<vector<int>> res;
        function<void(TreeNode * root, int s)> dfs = [&](TreeNode *root, int s) -> void
        {
            //mySolution_34 加了(s - root->val) < 0 的提前剪枝，若树节点或 target 存在负数，会误删合法路径 → 不安全。
             if (root == nullptr || (s - root -> val) < 0)
            {
                return;
            }
            s -= root->val;
            path.push_back(root->val);
            if (root->left == nullptr && root->right == nullptr && s == 0)
            {
                res.push_back(path);
            }
            dfs(root->left, s);
            dfs(root->right, s);
            path.pop_back();
        };
        dfs(root, target);
        return res;
    }
};

class offerSolution_34
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        vector<vector<int>> ans;
        vector<int> t;
        function<void(TreeNode * root, int s)> dfs = [&](TreeNode *root, int s)
        {
            if (!root)
            {
                return;
            }
            t.push_back(root->val);
            s -= root->val;
            if (!root->left && !root->right && !s)
            {
                ans.push_back(t);
            }
            dfs(root->left, s);
            dfs(root->right, s);
            t.pop_back();
        };
        dfs(root, target);
        return ans;
    }
};