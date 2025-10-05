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

/*
    二叉搜索树满足以下条件
    1.对于根节点，左子树所有节点的值 < 根节点的值 < 右子树所有节点的值
    2.任意节点的左右子树也是二叉搜索树，即同样满足条件1
*/

TreeNode *root = nullptr; // 初始化根节点

/* 查找节点 */
TreeNode *search(int num)
{
    TreeNode *cur = root;
    // 循环查找，越过叶节点后跳出
    while(cur != nullptr)
    {
        // 目标节点在cur的右子树中
        if(cur->val < num)
        {
            cur = cur->right;
        }
        // 目标节点在cur的左子树中
        else if(cur->val > num)
        {
            cur = cur->left;
        }
        // 找到目标节点，跳出循环
        else
        {
            break;
        }
    }
    // 返回目标节点
    return cur;
}

/*
    若待插入节点在树中已经存在，则不执行插入，直接返回
    为了实现插入节点，我们需要借助节点 pre 保存上一轮循环的节点。这样在遍历至 NONE 时，我们可以获取到其父节点，从而完成节点插入操作。
*/

/* 插入节点 */
void insert(int num)
{
    // 若树为空，则初始化根节点
    if (root == nullptr)
    {
        root = new TreeNode(num);
        return;
    }
    TreeNode *cur = root, *pre = nullptr;
    // 循环查找，越过叶节点后跳出
    while(cur != nullptr)
    {
        // 找到重复节点，直接返回
        if(cur->val == num)
        {
            return;
        }
        pre = cur;
        // 插入位置在 cur 的右子树中
        if(cur->val < num)
        {
            cur = cur->right;
        }
        // 插入位置在 cur 的左子树中
        else
        {
            cur = cur->left;
        }
    }
    // 插入节点
    TreeNode *node = new TreeNode(num);
    if(pre->val < num)
    {
        pre->right = node;
    }
    else
    {
        pre->left = node;
    }
}

/*
    当待删除节点的度为0时，表示该节点是叶节点，可以直接删除
    当待删除节点的度为1时，将待删除节点替换为其子节点即可
    当待删除节点的度为2时，需要找到该节点的中序遍历的下一个节点（即右子树的最左节点），用该节点的值覆盖待删除节点，然后递归删除该节点
*/

/* 删除节点 */
void remove(int num)
{
    // 若树为空，直接提前返回
    if(root == nullptr)
    {
        return;
    }
    TreeNode *cur = root, *pre = nullptr;
    // 循环查找,越过叶节点后跳出
    while(cur != nullptr)
    {
        // 找到待删除节点，跳出循环
        if(cur->val == num)
        {
            break;
        }
        pre = cur;
        // 待删除节点在 cur 的右子树中
        if(cur->val < num)
        {
            cur = cur->right;
        }
        // 待删除的节点在 cur 的左子树中
        else
        {
            cur = cur->left;
        }
    }
    // 若无待删除的节点，则直接返回
    if(cur == nullptr)
    {
        return;
    }
    // 子节点的数量 = 0 or 1
    if(cur->left == nullptr || cur->right == nullptr)
    {
        // 当子节点数量 = 0 / 1 时，child = nullptr / 该子节点
        TreeNode *child = cur->left != nullptr ? cur->left : cur->right;
        // 删除节点 cur
        if(cur != root)
        {
            if(pre->left == cur)
            {
                pre->left = child;
            }
            else
            {
                pre->right = child;
            }
        }
        else
        {
            // 若删除节点为根节点，则重新指定根节点
            root = child;
        }
        // 释放内存
        delete cur;
    }
    // 子节点数量 = 2
    else
    {
        // 获取中序遍历中的 cur 的下一节点
        TreeNode *tmp = cur->right;
        while(tmp->left != nullptr)
        {
            tmp = tmp->left;
        }
        int tmpval = tmp->val;
        // 递归删除节点 tmp
        remove(tmp->val);
        // 用 tmp 覆盖 cur
        cur->val = tmpval;
    }
}

