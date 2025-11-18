#include <bits/stdc++.h>

using namespace std;

// question : 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

class mySolution_49
{
    public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(2, 0);
        dp[1] = 1;
        int i = 2;
        for(; i <= 1690; i++ )
        {
            if(dp.size() > n)
            {
                break;
            }
            if (!(i % 2) || !(i % 3) || !(i % 5))
            {
                dp.push_back(i);
            }
        }  
        return dp[dp.size() - 1];
    }
    
};

// 每个丑数都是由前面的丑数乘以 2、3 或 5 得到的

class offerSolution_49_dp
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i)
        {
            int next2 = dp[p2] * 2, next3 = dp[p3] * 3, next5 = dp[p5] * 5;
            dp[i] = min(next2, min(next3, next5));
            if (dp[i] == next2)
                ++p2;
            if (dp[i] == next3)
                ++p3;
            if (dp[i] == next5)
                ++p5;
        }
        return dp[n - 1];
    }
};

class offerSolution_49_heap
{
public:
    int nthUglyNumber(int n)
    {
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1l);
        unordered_set<long> vis{{1l}};
        long ans = 1;
        vector<int> f = {2, 3, 5};
        while (n--)
        {
            ans = q.top();
            q.pop();
            for (int &v : f)
            {
                long nxt = ans * v;
                if (!vis.count(nxt))
                {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        return (int)ans;
    }
};

#if 0
int main()
{
    mySolution_49 sol;
    int n;
    cin >> n;
    cout << sol.nthUglyNumber(n) << endl;
    return 0;
}
#endif