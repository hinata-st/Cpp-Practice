#include <bits/stdc++.h>

using namespace std;

// question : 输入一个整数数组，其中不包含重复元素，返回所有可能的排列

/* 回溯算法：全排列 */
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    // 状态长度等于元素数量时， 记录解
    if (state.size() == choices.size())
    {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    for (int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        // 剪枝：检查选择是否合法
        if (!selected[i])
        {
            // 尝试：做出选择，更新状态
            state.push_back(choice);
            selected[i] = true;
            // 进行下一轮选择
            backtrack(state, choices, selected, res);
            // 回退：撤销选择，恢复到之前的状态
            state.pop_back();
            selected[i] = false;
        }
    }
}

/* 全排列 */
vector<vector<int>> permutationI(vector<int> &nums)
{
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res);
    return res;
}

// question :输入一个整数数组，数组中可能包含重复元素，返回所有不重复的排列。

/* 回溯算法：全排列 II */
void backtrackII(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    // 状态长度等于元素数量时， 记录解
    if (state.size() == choices.size())
    {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    unordered_set<int> duplicated;
    for (int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        // 剪枝：不允许重复选择元素,且 不允许重复选择相等的元素
        if (!selected[i] && duplicated.find(choice) == duplicated.end())
        {
            // 尝试：做出选择，更新状态
            state.push_back(choice);
            selected[i] = true;
            duplicated.emplace(choice);
            // 进行下一轮选择
            backtrackII(state, choices, selected, res);
            // 回退：撤销选择，恢复到之前的状态
            state.pop_back();
            selected[i] = false;
        }
    }
}

/*
bool dfs(int i, int j, int k)
{
    // ✅ 第一步：统一剪枝（在递归入口）
    if (终止条件)
        return true;
    if (越界 || 不匹配 || 已访问)
        return false;

    // ✅ 第二步：标记
    标记当前位置;

    // ✅ 第三步：遍历所有选择
    for (每个方向)
    {
        递归调用; // 子调用自己会剪枝
    }

    // ✅ 第四步：回溯
    恢复标记;
    return 结果;
}
*/