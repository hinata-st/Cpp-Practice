#include <bits/stdc++.h>

using namespace std;

// question :

class mySolution_46
{
    public:
    int translateNum(int num)
    {
        string s = to_string(num);
        int n = s.size();  
        int a = 1, b = 1; 
        for (int i = 1; i < n; ++i)
        {
            int c = b;
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 && two_digit <= 25)
            {
                c += a;
            }
            a = b;
            b = c;
        }
        return b;
    }
};

class offerSolution_46_dp
{
public:
    int translateNum(int num)
    {
        string s = to_string(num);
        int n = s.size();
        int a = 1, b = 1;
        for (int i = 1; i < n; ++i)
        {
            int c = b;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '6'))
            {
                c += a;
            }
            a = b;
            b = c;
        }
        return b;
    }
};

class offerSolution_46_dfs
{
public:
    int translateNum(int num)
    {
        string s = to_string(num);
        int n = s.size();
        int f[12]{};
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i >= n - 1)
            {
                return 1;
            }
            if (f[i])
            {
                return f[i];
            }
            int ans = dfs(i + 1);
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '6'))
            {
                ans += dfs(i + 2);
            }
            return f[i] = ans;
        };
        return dfs(0);
    }
};