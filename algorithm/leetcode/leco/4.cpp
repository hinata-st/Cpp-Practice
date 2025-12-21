#include <bits/stdc++.h>

using namespace std;

// question :给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。请你设计并实现时间复杂度为 O(n)的算法解决此问题。

// e.g. 输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是[1, 2, 3, 4]。它的长度为 4

class Solution
{
    public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest_streak = 0;

        for (const int& num : num_set)
        {
            // 仅在num是序列的起点时开始计数
            if (num_set.find(num - 1) == num_set.end())
            {
                int current_num = num;
                int current_streak = 1;

                // 向后查找连续的数字
                while (num_set.find(current_num + 1) != num_set.end())
                {
                    current_num += 1;
                    current_streak += 1;
                }

                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};