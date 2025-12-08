#include <bits/stdc++.h>

using namespace std;

// question : 0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

class mySolution_62
{
    public:
    int lastRemaining(int n, int m)
    {
        int rest = n;
        int dex = 0;
        int i = 0;
        unordered_set<int> st;
        while(rest > 1)
        {        
            if (i == m - 1)
            {
                st.insert(dex);
                dex = dex + 1;
                if (dex >= n)
                {
                    dex = 0;
                }
                while (st.find(dex) != st.end())
                {
                    dex++;
                    if (dex >= n)
                    {
                        dex = 0;
                    }
                }
                i = 0;
                rest--;
            }
            else
            {
                dex++;
                if (dex >= n)
                {
                    dex = 0;
                }
                while(st.find(dex) != st.end())
                {
                    dex++;
                    if (dex >= n)
                    {
                        dex = 0;
                    }
                }
                i++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (st.find(j) == st.end())
            {
                return j;
            }
        }
        return -1;
    }
};

class offerSolution_62
{
public:
    int lastRemaining(int n, int m)
    {
        int f = 0;
        for (int i = 2; i <= n; ++i)
        {
            f = (f + m) % i;
        }
        return f;
    }
};

class offerSolution_62_2
{
public:
    int lastRemaining(int n, int m)
    {
        return f(n, m);
    }

    int f(int n, int m)
    {
        if (n == 1)
        {
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }
};
