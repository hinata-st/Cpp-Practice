#include <bits/stdc++.h>

using namespace std;

// question : 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

class mySolution_61
{
public:
    // o(t) : O(nlogn) o(s): O(1)
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int zero_count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                ++zero_count;
            }
        }
        for (int i = zero_count + 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                return false; // 有重复牌，不可能是顺子
            }
            if (nums[i] - nums[i - 1] != 1)
            {
                if (zero_count >= nums[i] - nums[i - 1] - 1)
                {
                    zero_count -= (nums[i] - nums[i - 1] - 1);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

class offerSolution_61
{
public:
    // o(t) : O(n) o(s): O(1)
    bool isStraight(vector<int> &nums)
    {
        bool vis[14]{};
        int mi = 20, mx = -1;
        for (int &x : nums)
        {
            if (x == 0)
            {
                continue;
            }
            if (vis[x])
            {
                return false;
            }
            vis[x] = true;
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return mx - mi <= 4;
    }
};