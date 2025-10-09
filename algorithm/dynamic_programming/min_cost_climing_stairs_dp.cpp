#include <bits/stdc++.h>

using namespace std;

// question : 给定一个楼梯，你可以每步上 1 阶或者 2 阶，每一阶楼梯上都贴有一个非负整数，表示你在该台阶所需要付出的代价。给定一个非负整数数组cost,其中cost[i]表示在第i个台阶需要付出的代价,cost[0]为地面（起始点）。请计算最少需要付出多少代价才能到达顶部？


/* 爬楼梯最小代价：动态规划 */
int minCostClimbingStairsDP(vector<int> &cost)
{
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    // 初始化 dp 表，用于存储子问题的解
    vector<int> dp(n + 1);
    // 初始状态：预设最小子问题的解
    dp[1] = cost[1];
    dp[2] = cost[2];
    // 状态转移：从较小子问题逐步求解较大子问题
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return dp[n];
}

/* 爬楼梯最小代价：空间优化后的动态规划 */
int minCostClimbingStairsDPComp(vector<int> &cost)
{
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    int a = cost[1], b = cost[2];
    for (int i = 3; i <= n; i++)
    {
        int tmp = b;
        b = min(a, tmp) + cost[i];
        a = tmp;
    }
    return b;
}