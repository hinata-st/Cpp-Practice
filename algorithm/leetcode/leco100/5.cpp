#include <bits/stdc++.h>    

using namespace std;

// question:给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。请注意 ，必须在不复制数组的情况下原地对数组进行操作。 
class Solution
{
    public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.empty())
        {
            return;
        }
        unsigned int ptr_first = 0;
        unsigned int ptr_second = 0;
        unsigned int size = nums.size();
        while (ptr_first < size - 1)
        {
            if (ptr_second < size - 1)
            {
                ptr_second++;
            }
            if (nums[ptr_first] == 0 && nums[ptr_second] != 0)
            {
                swap(nums[ptr_first], nums[ptr_second]);
            }
            if (nums[ptr_first] != 0)
            {
                ptr_first++;
            }
            if (ptr_second == size - 1 && nums[ptr_second] == 0)
            {
                break;
            }
        }
    }
};

class offer_Solution
{
    public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size(), left = 0, right = 0;
        while(right < n)
        {
            if(nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};