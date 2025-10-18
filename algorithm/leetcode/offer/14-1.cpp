#include <bits/stdc++.h>

using namespace std;

// question : 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

class My_solution_14_1
{
    public:
    int cuttingRope(int n)
    {
        if (n <= 3)
        {
            return n - 1;
        }
        int res = 1;
        while (n > 4)
        {
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }

    int cuttingRope_dp(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; ++i)
        {
            for (int j = 1; j <= i/2; ++j)
            {
                dp[i] = max({dp[i], dp[i-j] * j, (i - j) * j});
            }
        }
        return dp[n];
    }
};

int main()
{
    My_solution_14_1 solu;
    int n = 10;
    cout << solu.cuttingRope(n) << endl;
    cout << solu.cuttingRope_dp(n) << endl;
    return 0;
}

class offer_Solution_14_1
{
public:
    int cuttingRope(int n)
    {
        vector<int> f(n + 1);
        f[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                f[i] = max({f[i], f[i - j] * j, (i - j) * j});
            }
        }
        return f[n];
    }
};