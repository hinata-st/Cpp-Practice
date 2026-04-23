#include <bits/stdc++.h>

using namespace std;

// question : 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++)
        {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};