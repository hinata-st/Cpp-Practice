#include <bits/stdc++.h>

using namespace std;

// question : 给定一个 n x m 的二维网络grid, 网络中的每个单元格包含一个非负整数，表示该单元格的代价。机器人以左上角单元格为起始点，每次只能向下或者向右移动一步，直至到达右下角单元格。请返回从左上角到右下角的最小路径和

// 问题求解步骤
// 1. 思考每轮的决策，定义状态，从而得到dp表
//    状态应包括行索引和列索引两个变量，记为[i, j],从起点[0,0]走到[i,j]的最小路径和，记为dp[i][j]
// 2. 找出最优子结构，进而推导出状态转移方程
//    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
// 3. 确定边界条件和状态转移顺序
//    处在首行的状态只能从其左边的状态得来，处在首行的状态只能从其上边的状态得来，因此首行i = 0和首列j = 0是边界条件

/* 最小路径和：暴力搜索 */
int minPathSumDFS(vector<vector<int>> &grid, int i, int j)
{
    // 若为左上角单元格，则终止搜索
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    // 若行列索引越界，则返回 +∞ 代价
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    // 计算从左上角到 (i-1, j) 和 (i, j-1) 的最小路径代价
    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);
    // 返回从左上角到 (i, j) 的最小路径代价
    return min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
}

/* 最小路径和：记忆化搜索 */
int minPathSumDFSMem(vector<vector<int>> &grid, vector<vector<int>> &mem, int i, int j)
{
    // 若为左上角单元格，则终止搜索
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    // 若行列索引越界，则返回 +∞ 代价
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    // 若已有记录，则直接返回
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    // 左边和上边单元格的最小路径代价
    int up = minPathSumDFSMem(grid, mem, i - 1, j);
    int left = minPathSumDFSMem(grid, mem, i, j - 1);
    // 记录并返回左上角到 (i, j) 的最小路径代价
    mem[i][j] = min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
    return mem[i][j];
}

/* 最小路径和：动态规划 */
int minPathSumDP(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    // 初始化 dp 表
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    // 状态转移：首行
    for (int j = 1; j < m; j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    // 状态转移：首列
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    // 状态转移：其余行和列
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

/* 最小路径和：空间优化后的动态规划 */
int minPathSumDPComp(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    // 初始化 dp 表
    vector<int> dp(m);
    // 状态转移：首行
    dp[0] = grid[0][0];
    for (int j = 1; j < m; j++)
    {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    // 状态转移：其余行
    for (int i = 1; i < n; i++)
    {
        // 状态转移：首列
        dp[0] = dp[0] + grid[i][0];
        // 状态转移：其余列
        for (int j = 1; j < m; j++)
        {
            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    return dp[m - 1];
}

int main()
{
    // 测试用例
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    int n = grid.size();
    int m = grid[0].size();

    cout << "输入网格:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 方法1：暴力搜索
    int res1 = minPathSumDFS(grid, n - 1, m - 1);
    cout << "最小路径和（暴力搜索）: " << res1 << endl;

    // 方法2：记忆化搜索
    vector<vector<int>> mem(n, vector<int>(m, -1));
    int res2 = minPathSumDFSMem(grid, mem, n - 1, m - 1);
    cout << "最小路径和（记忆化搜索）: " << res2 << endl;

    // 方法3：动态规划
    int res3 = minPathSumDP(grid);
    cout << "最小路径和（动态规划）: " << res3 << endl;

    // 方法4：空间优化的动态规划
    int res4 = minPathSumDPComp(grid);
    cout << "最小路径和（空间优化DP）: " << res4 << endl;

    return 0;
}