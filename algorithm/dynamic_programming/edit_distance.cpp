#include <bits/stdc++.h>

using namespace std;
// question : 输入两个字符串 s 和 t ,返回将 s 转换为 t 所需的最少编辑步数。
// 你可以在一个字符串中进行三种编辑操作：插入一个字符、删除一个字符、将字符替换为任意一个字符。

/*
    第一步：思考每轮的决策，定义状态，从而得到dp表
        状态为当前在 s 和 t 中考虑的第 i 和 第 j 个字符，记为[i,j]
        状态[i,j]对应的子问题：将s的前i个字符更改为t的前j个字符所需的最少编辑步数，记为dp[i][j]
    第二步：找出最优子结构，进而推导出状态转移
        dp[i,j] = min(dp[i,j-1],dp[i-1,j],dp[i-1,j-1]) + 1
        当s[i-1]和t[j-1]相同时，无须编辑当前字符，dp[i,j] = dp[i-1,j-1]
    第三步：确定边界条件和状态转移顺序
        当两个字符都为空时dp[0,0] = 0
        当s为空时，需插入j个字符，dp[0,j] = j
        当t为空时，需删除i个字符，dp[i,0] = i
*/

/* 编辑距离：动态规划 */
int editDistanceDP(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // 状态转移：首行首列
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = j;
    }
    // 状态转移：其余行和列
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                // 若两字符相等，则直接跳过此两字符
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // 最少编辑步数 = 插入、删除、替换这三种操作的最少编辑步数 + 1
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[n][m];
}

/* 编辑距离：空间优化后的动态规划 */
int editDistanceDPComp(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<int> dp(m + 1, 0);
    // 状态转移：首行
    for (int j = 1; j <= m; j++)
    {
        dp[j] = j;
    }
    // 状态转移：其余行
    for (int i = 1; i <= n; i++)
    {
        // 状态转移：首列
        int leftup = dp[0]; // 暂存 dp[i-1, j-1]
        dp[0] = i;
        // 状态转移：其余列
        for (int j = 1; j <= m; j++)
        {
            int temp = dp[j];
            if (s[i - 1] == t[j - 1])
            {
                // 若两字符相等，则直接跳过此两字符
                dp[j] = leftup;
            }
            else
            {
                // 最少编辑步数 = 插入、删除、替换这三种操作的最少编辑步数 + 1
                dp[j] = min(min(dp[j - 1], dp[j]), leftup) + 1;
            }
            leftup = temp; // 更新为下一轮的 dp[i-1, j-1]
        }
    }
    return dp[m];
}