#include <bits/stdc++.h>

using namespace std;

// question:在二叉树中搜索所有值为 7 的节点，请返回根节点到这些节点的路径，并要求路径中不包含值为3的节点。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 判断当前状态是否为解 */
bool isSolution(vector<TreeNode *> &state)
{
    return !state.empty() && state.back()->val == 7;
}

/* 记录解 */
void recordSolution(vector<TreeNode *> &state, vector<vector<TreeNode *>> &res)
{
    res.push_back(state);
}

/* 判断当前状态下，该选择是否合法 */
bool isValid(vector<TreeNode *> &state, TreeNode *choice)
{
    return choice != nullptr && choice->val != 3;
}

/* 更新状态 */
void makeChoice(vector<TreeNode *> &state, TreeNode *choice)
{
    state.push_back(choice);
}

/* 恢复状态 */
void undoChoice(vector<TreeNode *> &state, TreeNode *choice)
{
    state.pop_back();
}

/* 回溯算法 */
void backtrack(vector<TreeNode *> &state, vector<TreeNode *> &choices, vector<vector<TreeNode *>> &res)
{
    // 检查是否为解
    if(isSolution(state))
    {
        recordSolution(state, res);
    }
    // 遍历所有选择
    for (TreeNode *choice : choices)
    {
        // 剪枝：检查选择是否合法
        if (isValid(state, choice))
        {
            // 尝试：做出选择，更新状态
            makeChoice(state, choice);
            // 进行下一轮选择
            vector<TreeNode *> nextChoices{choice->left, choice->right};
            backtrack(state, nextChoices, res);
            // 回退：撤销选择，恢复到之前的状态
            undoChoice(state, choice);
        }
    }
}