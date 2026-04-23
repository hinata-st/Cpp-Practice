#include <bits/stdc++.h>

using namespace std;

// question :给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。你可以按任意顺序返回答案。
// e.g.:
// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = target - nums[i];
            if (num_map.find(num) != num_map.end())
            {
                return {num_map[num], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};