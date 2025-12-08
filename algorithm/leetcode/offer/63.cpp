#include <bits/stdc++.h>

using namespace std;

// question :

class mySolution_63
{
    public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1];
            for (int j = 0; j < i; j++)
            {
                dp[i] = max(dp[i], prices[i] - prices[j]);
            }
        }
        return dp[n - 1];
    }
};

class offerSolution_63
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mi = 1 << 30, ans = 0;
        for (int &x : prices)
        {
            ans = max(ans, x - mi);
            mi = min(mi, x);
        }
        return ans;
    }
};