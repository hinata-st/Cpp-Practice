#include <bits/stdc++.h>

using namespace std;

/* 二叉树节点结构 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 构建二叉树: 分治 */
/*
    将当前树的根节点在preorder中的索引标记为 i
    将当前树的根节点在inorder中的索引标记为 m
    将当前树在inorder中的索引区间记为[l, r]
*/
TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, int i, int l, int r)
{
    // 子树区间为空时终止
    if(r - l < 0)
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

/* 构建二叉树 */
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