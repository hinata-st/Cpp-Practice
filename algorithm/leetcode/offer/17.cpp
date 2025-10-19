#include <bits/stdc++.h>

using namespace std;

// question : 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

class my_solution
{
    public:
        vector<int> printNumbers(int n)
        {
            int maxNum = pow(10, n) - 1;
            vector<int> res;
            for (int i = 1; i <= maxNum; ++i)
            {
                res.push_back(i);
            }
            return res;
        }
};

class offer_Solution
{
public:
    vector<int> printNumbers(int n)
    {
        vector<int> ans(pow(10, n) - 1);
        iota(ans.begin(), ans.end(), 1);
        return ans;
    }

    vector<string> print(int n)
    {
        vector<string> ans;
        string s;
        function<void(int, int)> dfs = [&](int i, int j)
        {
            if (i == j)
            {
                ans.push_back(s);
                return;
            }
            int k = i ? 0 : 1;
            for (; k < 10; ++k)
            {
                s.push_back(k + '0');
                dfs(i + 1, j);
                s.pop_back();
            }
        };
        for (int i = 1; i <= n; ++i)
        {
            dfs(0, i);
        }
        return ans;
    }
};
