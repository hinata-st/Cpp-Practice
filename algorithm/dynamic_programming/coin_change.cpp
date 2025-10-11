#include <bits/stdc++.h>

using namespace std;

// question : 给定n种硬币，第i种硬币的面值为coins[i-1],目标金额为amt,每种硬币可以重复选取,问能够凑出目标金额的最少硬币数量。如果无法凑出目标金额，则返回-1。


/*
    第一步：思考每轮的决策，定义状态，从而得到dp表
    前i种硬币能够凑出金额a的最少硬币数量，记为dp[i,a]
    第二步：找出最优子结构，进而推导出状态转移方程
    dp[i,a] = min(dp[i-1,a], dp[i,a-coins[i-1]]+1)  
    第三步：确定边界条件和状态转移顺序
    当目标金额为0时，凑出它最少硬币数量为0，即首列所有dp[i,0]=0
    当没有硬币时，无法凑出正整数金额，设为amt+,即首行所有dp[0,a]=amt+ (a>0)
*/
/* 零钱兑换：动态规划 */
int coinChangeDP(vector<int> &coins, int amt)
{
    int n = coins.size();
    int MAX = amt + 1;
    // 初始化 dp 表
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));
    // 状态转移：首行首列
    for (int a = 1; a <= amt; a++)
    {
        dp[0][a] = MAX;
    }
    // 状态转移：其余行和列
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amt; a++)
        {
            if (coins[i - 1] > a)
            {
                // 若超过目标金额，则不选硬币 i
                dp[i][a] = dp[i - 1][a];
            }
            else
            {
                // 不选和选硬币 i 这两种方案的较小值
                dp[i][a] = min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amt] != MAX ? dp[n][amt] : -1;
}

/* 零钱兑换：空间优化后的动态规划 */
int coinChangeDPComp(vector<int> &coins, int amt)
{
    int n = coins.size();
    int MAX = amt + 1;
    // 初始化 dp 表
    vector<int> dp(amt + 1, MAX);
    dp[0] = 0;
    // 状态转移
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amt; a++)
        {
            if (coins[i - 1] > a)
            {
                // 若超过目标金额，则不选硬币 i
                dp[a] = dp[a];
            }
            else
            {
                // 不选和选硬币 i 这两种方案的较小值
                dp[a] = min(dp[a], dp[a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[amt] != MAX ? dp[amt] : -1;
}

// question II : 给定n种硬币,第i种硬币的面值为coin[i-1],目标金额为amt,每种硬币可以重复选取，问凑出目标金额的硬币组合数量。

/* 零钱兑换 II：动态规划 */
int coinChangeIIDP(vector<int> &coins, int amt)
{
    int n = coins.size();
    // 初始化 dp 表
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));
    // 初始化首列
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    // 状态转移
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amt; a++)
        {
            if (coins[i - 1] > a)
            {
                // 若超过目标金额，则不选硬币 i
                dp[i][a] = dp[i - 1][a];
            }
            else
            {
                // 不选和选硬币 i 这两种方案之和
                dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]];
            }
        }
    }
    return dp[n][amt];
}

/* 零钱兑换 II：空间优化后的动态规划 */
int coinChangeIIDPComp(vector<int> &coins, int amt)
{
    int n = coins.size();
    // 初始化 dp 表
    vector<int> dp(amt + 1, 0);
    dp[0] = 1;
    // 状态转移
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amt; a++)
        {
            if (coins[i - 1] > a)
            {
                // 若超过目标金额，则不选硬币 i
                dp[a] = dp[a];
            }
            else
            {
                // 不选和选硬币 i 这两种方案之和
                dp[a] = dp[a] + dp[a - coins[i - 1]];
            }
        }
    }
    return dp[amt];
}
