#include <bits/stdc++.h>

using namespace std;

// question : 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

class my_solution_13
{
    public : 
        int cal_digit_sum(int num)
        {
            int sum = 0;
            while (num)
            {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }
        int movingCount(int m, int n, int k)
        {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int count = 0;
            dfs(0, 0, m, n, k, visited, count);
            return count;
        }
    private :
        void dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited, int& count)
        {
            if(cal_digit_sum(i) + cal_digit_sum(j) <= k)
            {
                count++;
            }
            visited[i][j] = true;
            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            if(i >= 0 && i < m && j >= 0 && j < n && !visited[i][j])
            {
                for(auto dir : directions)
                {
                    dfs(i + dir[0], j + dir[1], m, n, k, visited, count);
                    visited[i][j] = false;
                }
            }
            visited[i][j] = false;
        }
};

/* int main()
{
    my_solution_13 sol;
    int m, n, k;
    cin >> m >> n >> k;
    int res = sol.movingCount(m, n, k);
    cout << res << endl;
    return 0;
} */
/*
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        bool vis[m][n];
        memset(vis, false, sizeof vis);
        auto f = [](int x)
        {
            return x / 10 + x % 10;
        };
        function<int(int i, int j)> dfs = [&](int i, int j) -> int
        {
            if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || f(i) + f(j) > k)
            {
                return false;
            }
            vis[i][j] = true;
            return 1 + dfs(i + 1, j) + dfs(i, j + 1);
        };
        return dfs(0, 0);
    }
};*/

class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        // 访问标记数组
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Lambda：计算数位和
        auto digitSum = [](int x) -> int
        {
            int sum = 0;
            while (x)
            {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        // Lambda：DFS
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            // 剪枝
            if (i < 0 || i >= m || j < 0 || j >= n ||
                visited[i][j] ||
                digitSum(i) + digitSum(j) > k)
            {
                return 0;
            }

            // 标记
            visited[i][j] = true;

            // 只向右和向下搜索
            return 1 + dfs(i + 1, j) + dfs(i, j + 1);
        };

        return dfs(0, 0);
    }
};