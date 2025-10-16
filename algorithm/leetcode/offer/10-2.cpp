#include <bits/stdc++.h>

using namespace std;

// question : 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。

class my_solution
{
    public:
        long int numWays_1(int n)
        {
            vector<long int> dp(n + 1, 0);
            dp[0] = 1;
            dp[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
            }
            return dp[n];
        }

        long int numWays_2(int n)
        {
            long int a = 1, b = 1, c = 1;
            for (int i = 2; i <= n; i++)
            {
                c = (a + b) % 1000000007;
                a = b;
                b = c;
            }
            return c;
        }
};
//-----------------------------------------------
class my_solutin_refavtor
{
    int climbingStairsDP(int n)
    {
        if (n == 1 || n == 2)
            return n;
        // 初始化 dp 表，用于存储子问题的解
        vector<int> dp(n + 1);
        // 初始状态：预设最小子问题的解
        dp[1] = 1;
        dp[2] = 2;
        // 状态转移：从较小子问题逐步求解较大子问题
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    /* 爬楼梯：空间优化后的动态规划 */
    int climbingStairsDPComp(int n)
    {
        if (n == 1 || n == 2)
            return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++)
        {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};
//-----------------------------------------------
class Solution
{
public:
    int numWays(int n)
    {
        int a = 1, b = 1;
        while (n--)
        {
            int c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return a;
    }
};

int main()
{
    my_solution test;
    int n;
    cin >> n;
    cout << test.numWays_2(n) << endl;
    return 0;
}