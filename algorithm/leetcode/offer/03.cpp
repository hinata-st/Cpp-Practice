
// question:在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

#include <bits/stdc++.h>

using namespace std;

/*方法一：哈希表*/

class Solution
{
    public:
        int findRepeatNumber(vector<int> &nums)
        {
            unordered_set<int> vis;
            for (int i = 0;; ++i)
            {
                if(vis.count(nums[i]))
                {
                    return nums[i];
                }
                vis.insert(nums[i]);
            }
        }
};

int findRepeatNumber(vector<int> &nums)
{
    unordered_map<int, int> count;
    for(int num : nums)
    {
        if(count.find(num) != count.end())
        {
            return num;
        }
        else
        {
            count.emplace(num, 1);
        }
    }
    return -1;
}

int main()
{
    vector<int> inputNums;
    int num;
    while(cin >> num)
    {
        inputNums.push_back(num);
    }
    cout << findRepeatNumber(inputNums) << endl;
    return 0;
}

/* 方法二：排序*/
class Solution2
{
    public:
        int findRepeatNumber(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            for (int i = 1;;i++)
            {
                if(nums[i] == nums[i + 1])
                {
                    return nums[i];
                }
            }
            return -1;
        }
};

/* 方法三：原地交换*/
class Solution3
{
    public:
        int findRepeatNumber(vector<int> &nums)
        {
            for (int i = 0;; ++i)
            {
                while (nums[i] != i)
                {
                    int j = nums[i];
                    if (nums[j] == j)
                    {
                        return j;
                    }
                    swap(nums[i], nums[j]);
                }
            }
        }
};