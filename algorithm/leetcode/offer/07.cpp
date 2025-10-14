#include <bits/stdc++.h>

using namespace std;

// question : 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//my solution
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};
// index_nowTreePreorder  i
// index_nowTreeInorder   m
// indexRange_nowTree    [l,r]
//             index_rootPreorder       indexRange_tree
// now_tree    i                        l,r
// left_tree   i+1                      l,m-1
// right_tree  i+m-l+1                  m+1,r
class Solution
{
public:
    TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, int i, int l, int r)
    {
        // 子树区间为空时终止
        if (r - l < 0)
        {
            return NULL;
        }
        // 初始化根节点
        TreeNode *root = new TreeNode(preorder[i]);
        // 查询 m , 从而划分左右子树
        int m = inorderMap[preorder[i]];
        // 子问题：构建左子树
        root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
        // 子问题：构建右子树
        root->right = dfs(preorder, inorderMap, i + m - l + 1, m + 1, r);
        // 返回根节点
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 初始化哈希表，储存 inorder 元素到索引的映射
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        TreeNode *root = dfs(preorder, inorderMap, 0, 0, inorder.size() - 1);
        return root;
    }
};

//哈希表+递归
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> d;
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
        {
            d[inorder[i]] = i;
        }
        function<TreeNode *(int, int, int)> dfs = [&](int i, int j, int n) -> TreeNode *
        {
            if (n < 1)
            {
                return nullptr;
            }
            int k = d[preorder[i]];
            int l = k - j;
            TreeNode *root = new TreeNode(preorder[i]);
            root->left = dfs(i + 1, j, l);
            root->right = dfs(i + 1 + l, k + 1, n - l - 1);
            return root;
        };
        return dfs(0, 0, n);
    }
};