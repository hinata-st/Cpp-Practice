#include <bits/stdc++.h>

using namespace std;

// question : 给定一共有 n 阶楼梯，你可以每步上 1 阶或者 2 阶，请问有多少种方案可以爬到楼顶？

/*
    将数组dp称为dp表，dp[i]表示状态i对应子问题的解
    将最小子问题对应的状态(第一阶和第二阶楼梯)称为初始状态
    将递推公式dp[i] = dp[i-1] + dp[i-2]称为状态转移方程
*/

/* 爬楼梯：动态规划 */
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