#include <bits/stdc++.h>

using namespace std;

// question : 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）

class mySolution_64
{
    public:
    int sumNums(int n)
    {
        int sum = 0;
        (n == 1) && (sum += 1);
        (n > 1) && (sum += sumNums(n - 1) + n);
        return sum;
    }
};

class offerSolution_64
{
public:
    int sumNums(int n)
    {
        n && (n += sumNums(n - 1));
        return n;
    }
};