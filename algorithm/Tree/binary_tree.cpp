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

/* binary_tree_bfs */
/* 层序遍历 */
vector<int> levelOrder(TreeNode *root)
{
    //初始化队列，加入根节点
    queue<TreeNode *> queue;
    queue.push(root);
    //初始化一个列表，用于保存遍历序列
    vector<int> vec;
    while(!queue.empty())
    {
        TreeNode *node = queue.front();
        queue.pop();
        vec.push_back(node->val);
        if(node->left != nullptr)
        {
            queue.push(node->left);
        }
        if(node->right != nullptr)
        {
            queue.push(node->right);
        }

    }
    return vec;
}

vector<int> vec_dfs;

/* binary_tree_dfs */
/* 前序遍历 */
void preOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    // 访问优先级: 根节点 -> 左子树 -> 右子树
    vec_dfs.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    // 访问优先级: 左子树 -> 根节点 -> 右子树
    inOrder(root->left);
    vec_dfs.push_back(root->val);
    inOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    // 访问优先级: 左子树 -> 根节点 -> 右子树
    postOrder(root->left);
    postOrder(root->right);
    vec_dfs.push_back(root->val);
}   

/* 数组表示下的二叉树类 */
class ArrayBinaryTree
{
    public:
        /* 构造方法 */
        ArrayBinaryTree(vector<int> arr)
        {
            tree = arr;
        }

        /*  列表容量 */
        int size()
        {
            return tree.size();
        }

        /* 获取索引为i的节点值 */
        int val(int i)
        {
            // 若索引越界，则返回INT_MAX,代表空位
            if(i < 0 || i >= tree.size())
            {
                return INT_MAX;
            }
            return tree[i];
        }

        /* 获取索引为 i 的左子节点的索引 */
        int left(int i)
        {
            return 2 * i + 1;
        }

        /* 获取索引为 i 的右子节点的索引 */
        int right(int i)
        {
            return 2 * i + 2;
        }

        /* 获取索引为 i 的父节点的索引 */
        int parent(int i )
        {
            return (i - 1) / 2;
        }

        /* 层序遍历 */
        vector<int> levelOrder()
        {
            vector<int> res;
            //直接遍历数组
            for (int i = 0; i < size(); i++)
            {
                if(val(i) != INT_MAX)
                {
                    res.push_back(val(i));
                }
            }
            return res;
        }

        /* 前序遍历 */
        vector<int> preOrder()
        {
            vector<int> res;
            dfs(0, "pre", res);
            return res;
        }

        /* 中序遍历 */
        vector<int> inOrder()   
        {
            vector<int> res;
            dfs(0, "in", res);
            return res;
        }

        /* 后序遍历 */
        vector<int> postOrder()
        {
            vector<int> res;
            dfs(0, "post", res);
            return res;
        }   

    private:
        vector<int> tree;

        /* 深度优先遍历 */
        void dfs(int i, string order, vector<int> &res)
        {
            // 若为空位，则返回
            if(val(i) == INT_MAX)
            {
                return;
            }
            // 前序遍历
            if(order == "pre")
            {
                res.push_back(val(i));
            }
            dfs(left(i), order, res);
            // 中序遍历
            if(order == "in")
            {
                res.push_back(val(i));
            }
            dfs(right(i), order, res);
            // 后序遍历
            if(order == "post")
            {
                res.push_back(val(i));
            }
        }
};