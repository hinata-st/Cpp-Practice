#include <bits/stdc++.h>

using namespace std;

// question : 

class mySolution_42
{
    public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        int res = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

class offerSolution_42
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int f = 0;
        for (int &x : nums)
        {
            f = max(f, 0) + x;
            ans = max(ans, f);
        }
        return ans;
    }
};