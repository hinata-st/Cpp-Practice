#include <bits/stdc++.h>

using namespace std;

/* AVL 树节点类 */
struct TreeNode
{
    int val{};              // 节点值
    int height = 0;         // 节点高度
    TreeNode *left{};       // 左子节点
    TreeNode *right{};      // 右子节点
    TreeNode() = default;
    explicit TreeNode(int x) : val(x){}
};

/* 获取节点的高度 */
int height(TreeNode *node)
{
    // 空节点高度为 -1 , 叶节点高度为 0
    return node == nullptr ? -1 : node->height;
}

/* 更新节点的高度 */
void uodateHeight(TreeNode *node)
{
    // 节点高度等于最高子树高度 + 1
    node->height = max(height(node->left), height(node->right)) + 1;
}

/* 获取平衡因子 */
int balanceFactor(TreeNode *node)
{
    // 空节点平衡因子为 0 
    if(node == nullptr)
    {
        return 0;
    }
    // 节点平衡因子 = 左子树高度 - 右子树高度
    return height(node->left) - height(node->right);
}