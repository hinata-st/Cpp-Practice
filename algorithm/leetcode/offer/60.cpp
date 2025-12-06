#include <bits/stdc++.h>

using namespace std;

// question :  把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

class mySolution_60
{
    public:
    vector<float> dicesProbability(int n)
    {
        vector<float> dp(5 * n + 1,0.0);
        int total = pow(6,n);
        dp[0] = 1.0 / total;
        for (int i = 1; i < 6; ++i)
        {
            if (n == 1)
            {
                dp[i] = 1.0 / total;
            }
            else 
            {
                dp[i] = dp[i - 1] + 1.0 / total;
            }
        }
        for (int i = 7; i < 5 * n + 1 - 5; ++i)
        {
            dp[i] = dp[i - 1];
        }
        for (int i = 5 * n + 1 - 5; i < 5 * n + 2 && n != 1; ++i)
        {
            dp[i] = dp[i - 1] - 1.0 / total;
        }
        return dp;
    }
};

class offerSolution_60
{
public:
    vector<double> dicesProbability(int n)
    {
        int f[n + 1][6 * n + 1];
        memset(f, 0, sizeof f);
        for (int j = 1; j <= 6; ++j)
        {
            f[1][j] = 1;
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j <= 6 * i; ++j)
            {
                for (int k = 1; k <= 6; ++k)
                {
                    if (j >= k)
                    {
                        f[i][j] += f[i - 1][j - k];
                    }
                }
            }
        }
        vector<double> ans;
        double m = pow(6, n);
        for (int j = n; j <= 6 * n; ++j)
        {
            ans.push_back(f[n][j] / m);
        }
        return ans;
    }
};

class mySolution_60_2
{
    public:
    vector<float> dicesProbability(int n)
    {
        int f[n + 1][6 * n + 1];
        memset(f, 0, sizeof f);
        for (int j = 1; j <= 6; ++j)
        {
            f[1][j] = 1;
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j <= 6 * i; ++j)
            {
                for (int k = 1; k <= 6; ++k)
                {
                    if (j >= k)
                    {
                        f[i][j] += f[i - 1][j - k];
                    }
                }
            }
        }
        vector<float> ans;
        float m = pow(6, n);
        for (int j = n; j <= 6 * n; ++j)
        {
            ans.push_back(f[n][j] / m);
        } 
        return ans;
    }
};