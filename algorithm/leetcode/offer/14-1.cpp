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

/* int main()
{
    My_solution_14_1 solu;
    int n = 10;
    cout << solu.cuttingRope(n) << endl;
    cout << solu.cuttingRope_dp(n) << endl;
    return 0;
} */
// 动态规划
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
// 数学贪心
class offer_Solution
{
public:
    int cuttingRope(int n)
    {
        if (n < 4)
        {
            return n - 1;
        }
        if (n % 3 == 0)
        {
            return pow(3, n / 3);
        }
        if (n % 3 == 1)
        {
            return pow(3, n / 3 - 1) * 4;
        }
        return pow(3, n / 3) * 2;
    }
};

/* 最大切分乘积：贪心 */
int maxProductCutting(int n)
{
    // 当 n <= 3 时，必须切分出一个 1
    if (n <= 3)
    {
        return 1 * (n - 1);
    }
    // 贪心地切分出 3 ，a 为 3 的个数，b 为余数
    int a = n / 3;
    int b = n % 3;
    if (b == 1)
    {
        // 当余数为 1 时，将一对 1 * 3 转化为 2 * 2
        return (int)pow(3, a - 1) * 2 * 2;
    }
    if (b == 2)
    {
        // 当余数为 2 时，不做处理
        return (int)pow(3, a) * 2;
    }
    // 当余数为 0 时，不做处理
    return (int)pow(3, a);
}