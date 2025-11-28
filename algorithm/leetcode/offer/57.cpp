#include <bits/stdc++.h>

using namespace std;

// question : 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

class mySolution_57
{
    public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_set<int> hashset;
        for (int num : nums)
        {
            int complement = target - num;
            if (hashset.count(complement))
            {
                return {complement, num};
            }
            hashset.insert(num);
        }
        return {};
    }
};

class offerSolution_57
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (1)
        {
            if (nums[l] + nums[r] == target)
            {
                return {nums[l], nums[r]};
            }
            if (nums[l] + nums[r] > target)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
    }
};