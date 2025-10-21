#include  <bits/stdc++.h>

using namespace std;

// question : 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：F(0) = 0,   F(1) = 1  F(N) = F(N - 1) + F(N - 2), 其中 N > 1.

// my solution
class my_Solution_10_1
{
    public:
        int fib1(int n)//递归
        {
            if(n == 0)
            {
                return 0;
            }
            if(n == 1)
            {
                return 1;
            }
            return (fib1(n-1) + fib1(n-2)) % 1000000007;
        }
        int fib2(int n)//动态规划
        {
            vector<int> dp(n+1,0);
            dp[0] = 0;//可空间优化
            dp[1] = 1;
            for(int i = 2; i <= n; i++)
            {
                dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
            }
            return dp[n];
        }
};

// offer solution
class offer_Solution_10_1
{
public:
    int fib(int n)
    {
        int a = 0, b = 1;
        while (n--)
        {
            int c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return a;
    }
};