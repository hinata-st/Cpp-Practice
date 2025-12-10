#include <bits/stdc++.h>

using namespace std;

// question : 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

class offerSolution_65
{
public:
    int add(int a, int b)
    {
        while (b)
        {
            unsigned int c = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};