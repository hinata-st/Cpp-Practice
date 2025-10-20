#include <bits/stdc++.h>

using namespace std;

// question : 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

class My_solution
{
    public : 
        vector<int> exchange(vector<int> &nums)
        {
            vector<int> result;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] % 2 != 0)
                {
                    result.push_back(nums[i]);
                }
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] % 2 == 0)
                {
                    result.push_back(nums[i]);
                }
            }
            return result;
        }
};

class offer_Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] & 1)
            {
                swap(nums[i], nums[j++]);
            }
        }
        return nums;
    }
};