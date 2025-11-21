#include <bits/stdc++.h>

using namespace std;

// question :统计一个数字在排序数组中出现的次数。

class mySolutoin_53_1
{
    public:
    int search(vector<int>& nums,int target)
    {
        auto l = lower_bound(nums.begin(),nums.end(),target);
        auto r = upper_bound(nums.begin(),nums.end(),target);
        return r - l;
    }
};