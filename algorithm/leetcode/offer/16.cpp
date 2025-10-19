#include <bits/stdc++.h>

using namespace std;

// question : 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

class my_solution
{
    public:
    double myPow(double x, int n)
    {
        int sign = 1;
        double res = x;
        if(n == 1)
        {
            return x;
        }
        if(n == 0)
        {
            return 1;
        }        
        while(n > 1)
        {
            x *= res;
            n = n - 1;
        }
        while(n < -1)
        {
            sign = 0;
            x *=  res;
            n++;
        }
        if(sign == 0)
        {
            return 1/x;
        }
        return x;  
    }
};

int main()
{
    my_solution sol;
    double x;
    int n;
    cin >> x >> n;
    cout << fixed << setprecision(5);
    cout << sol.myPow(x, n) << endl;
    return 0;
}

class offer_Solution
{
public:
    double myPow(double x, int n)
    {
        auto qpow = [](double a, long long n)
        {
            double ans = 1;
            for (; n; n >>= 1)
            {
                if (n & 1)
                {
                    ans *= a;
                }
                a *= a;
            }
            return ans;
        };
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long long)n);
    }
};
/*
2 ^ 10 = 2 ^ (1010)₂
 = 2 ^ (1×2³ + 0×2² + 1×2¹ + 0×2⁰) 
 = 2 ^ 8 * 2 ^ 2 
 = 256 * 4 
 = 1024 ✅*/