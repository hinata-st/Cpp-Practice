#include <bits/stdc++.h>

using namespace std;

// question : 设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

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

class offerSolution_63_2
{
    public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp(prices.size() + 1, 0);
        int min_price = INT_MAX;
        dp[0] = 0;
        for (int i = 1; i <= prices.size(); i++)
        {
            min_price = min(min_price, prices[i - 1]);
            dp[i] = max(dp[i - 1], prices[i - 1] - min_price);
        }
        return dp[prices.size()];
    }
};