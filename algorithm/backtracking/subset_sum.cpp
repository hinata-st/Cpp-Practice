#include <bits/stdc++.h>

using namespace std;

// question : 给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的元素和等于 target 。给定数组无重复元素，每个元素可以被选取多次。请以列表形式返回这些组合，列表中不应包含重复组合。

/* 回溯算法 : 子集合 I */
void backtrackI(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res)
{
    // 子集和邓宇 target 时， 记录解
    if(target == 0)
    {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    // 剪枝二： 从 start 开始遍历 ,避免生成重复子集
    for (int i = start; i < choices.size(); i++)
    {
        // 剪枝一 ： 若子集和超过 target, 则直接结束循环
        // 这是因为数组已排序，后边元素更大，子集和一定超过 target
        if (choices[i] > target)
        {
            break;
        }
        // 尝试 ： 做出选择，更新 target， start
        state.push_back(choices[i]);
        // 进行下一轮选择 
        backtrackI(state, target - choices[i], choices, i, res);
        // 回退 ： 撤销选择，恢复到之前的状态
        state.pop_back();
    }
}

/* 求解子集和 I */
vector<vector<int>> subsetSumI(vector<int> &nums, int target)
{
    vector<int> state;                      // 状态 （子集）
    sort(nums.begin(), nums.end());         // 对nums 进行排序
    int start = 0;                          // 遍历起始点
    vector<vector<int>> res;                // 结果列表（子集列表）
    backtrackI(state, target, nums, start, res); 
    return res;
}

// question : 给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的元素和等于 target 。给定数组可能包含重复元素，每个元素只可被选择一次。请以列表形式返回这些组合，列表中不应包含重复组合。

/* 回溯算法：子集和 II */
void backtrackII(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res)
{
    // 子集和等于 target 时，记录解
    if (target == 0)
    {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    // 剪枝二：从 start 开始遍历，避免生成重复子集
    // 剪枝三：从 start 开始遍历，避免重复选择同一元素
    for (int i = start; i < choices.size(); i++)
    {
        // 剪枝一：若子集和超过 target ，则直接结束循环
        // 这是因为数组已排序，后边元素更大，子集和一定超过 target
        if (target - choices[i] < 0)
        {
            break;
        }
        // 剪枝四：如果该元素与左边元素相等，说明该搜索分支重复，直接跳过
        if (i > start && choices[i] == choices[i - 1])
        {
            continue;
        }
        // 尝试：做出选择，更新 target, start
        state.push_back(choices[i]);
        // 进行下一轮选择
        backtrackII(state, target - choices[i], choices, i + 1, res);
        // 回退：撤销选择，恢复到之前的状态
        state.pop_back();
    }
}

/* 求解子集和 II */
vector<vector<int>> subsetSumII(vector<int> &nums, int target)
{
    vector<int> state;              // 状态（子集）
    sort(nums.begin(), nums.end()); // 对 nums 进行排序
    int start = 0;                  // 遍历起始点
    vector<vector<int>> res;        // 结果列表（子集列表）
    backtrackII(state, target, nums, start, res);
    return res;
}