#include <bits/stdc++.h>

using namespace std;

// question : 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

class my_solution_19
{
    public:
    bool isMatch(string s, string p)
    {
        vector<int>::size_type size_s = s.size();
        vector<int>::size_type size_p = p.size();
        int k = 0;
        function<bool(int, int, int)> dps;
        dps = [&](int i, int j, int k) -> bool
        {
            
            //递归终止条件：字符串和模式串都匹配完
            if(k == size_s && j == size_p)
            {
                return true;
            }
            // 如果模式串匹配完但字符串未匹配完，返回false
            if(j == size_p)
            {
                return false;
            }
            
            //剪枝
            if(s[i] != p[j])
            {
                return false;
            }
            //遍历所有情况
            if(p[j] == '.' && p[j + 1] != '*' && j + 1 < size_p)
            {
                return dps(i + 1, j + 1, k + 1);
            }
            else if (p[j] == '.' && p[j + 1] == '*' && j + 1 < size_p)
            {
                int temp = i;
                while(temp < size_s)
                {
                    temp++;
                }
                return dps(temp, j + 2, k + (temp - i)) || dps(i, j + 2, k);
            }
            else if (i == size_s - 1 && j == size_p - 1 && s[i] == p[j])
            {
                return true;
            }
            else if (p[j] != '.' && p[j + 1] == '*' && j + 1 < size_p)
            {
                int temp = i;
                while(s[temp] == p[j])
                {
                    temp++;
                }
                return dps(temp, j + 2, k + (temp - i)) || dps(i, j + 2, k);
            }
            else
            {
                return dps(i + 1, j + 1, k + 1);
            }


        };
        return dps(0, 0, 0);
    }
};

class my_solution_19_fixed
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();

        // 记忆化数组（0=未计算, 1=true, -1=false）
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));

        function<bool(int, int)> dfs = [&](int i, int j) -> bool
        {
            // 检查缓存
            if (memo[i][j] != 0)
                return memo[i][j] == 1;

            // 终止条件：p 匹配完
            if (j >= n)
            {
                bool res = (i >= m);
                memo[i][j] = res ? 1 : -1;
                return res;
            }

            // 检查当前字符是否匹配
            bool first_match = (i < m) && (s[i] == p[j] || p[j] == '.');

            bool result;

            // 情况1：p[j+1] == '*'
            if (j + 1 < n && p[j + 1] == '*')
            {
                // x* 匹配 0 个 或 匹配 1+ 个
                result = dfs(i, j + 2) || (first_match && dfs(i + 1, j));
            }
            // 情况2：普通匹配
            else
            {
                result = first_match && dfs(i + 1, j + 1);
            }

            memo[i][j] = result ? 1 : -1;
            return result;
        };

        return dfs(0, 0);
    }
};

class offer_Solution_19
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        function<bool(int, int)> dfs = [&](int i, int j) -> bool
        {
            if (j >= n)
            {
                return i == m;
            }
            if (f[i][j])
            {
                return f[i][j] == 1;
            }
            int res = -1;
            if (j + 1 < n && p[j + 1] == '*')
            {
                if (dfs(i, j + 2) or (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j)))
                {
                    res = 1;
                }
            }
            else if (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j + 1))
            {
                res = 1;
            }
            f[i][j] = res;
            return res == 1;
        };
        return dfs(0, 0);
    }
};
/* 
int main() {
    string s, p;
    cin >> s >> p;
    offer_Solution_19 a;
    bool res = a.isMatch(s, p);
    cout << res << endl;
    return 0;
} */

class my_solution_19_second
{
    public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> visited(m + 1, vector<int>(n + 1, 0));
        function<bool(int, int)> dfs = [&](int i, int j) -> bool
        {
            int res = -1;
            if(j == n)
            {
                return i == m;
            }
            if(visited[i][j] != 0)
            {
                return visited[i][j] == 1;
            }
            if(j + 1 < n && p[j + 1] == '*')
            {
                if(dfs(i ,j + 2) || (i < m &&(s[i] == p[j] || p[j] == '.') && dfs(i + 1, j)))
                {
                    res = 1;
                }
            }
            else if (i < m && (s[i] == p[j] || p[j] == '.') && dfs(i + 1, j + 1))
            {
                res = 1;
            }
            else
            {
                res = 0;
            }
            visited[i][j] = res;
            return res == 1;
        };
        return dfs(0, 0);
    }
};