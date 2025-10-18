#include <bits/stdc++.h>

using namespace std;

// question : 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。

class My_solution_14_2
{
    public:
    int cuttingRope(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n] % 1000000007;
    }
};

class offer_Solution
{
public:
    int cuttingRope(int n)
    {
        if (n < 4)
        {
            return n - 1;
        }
        const int mod = 1e9 + 7;
        auto qpow = [&](long long a, long long n)
        {
            long long ans = 1;
            for (; n; n >>= 1)
            {
                if (n & 1)
                {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int)ans;
        };
        if (n % 3 == 0)
        {
            return qpow(3, n / 3);
        }
        if (n % 3 == 1)
        {
            return qpow(3, n / 3 - 1) * 4L % mod;
        }
        return qpow(3, n / 3) * 2 % mod;
    }
};