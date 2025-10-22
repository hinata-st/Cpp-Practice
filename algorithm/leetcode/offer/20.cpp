#include <bits/stdc++.h>

using namespace std;

// question : 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

class Mysolution_20
{
    public:
    bool isNumb(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while(i < j && s[i] == ' ')
        {
            i++;
        }
        while(i < j && s[j] == ' ')
        {
            j--;
        }
        if(i > j)
        {
            return false;
        }
        bool digit = false, dot = false, e = false;
        for (; i <= j; ++i)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                if (i && s[i - 1] != ' ' && s[i - 1] != 'e' && s[i - 1] != 'E')
                {
                    return false;
                }
            }
            else if (isdigit(s[i]))
            {
                digit = true;
            }
            else if (s[i] == '.')
            {
                if (dot || e)
                {
                    return false;
                }
                dot = true;
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (!digit || e)
                {
                    return false;
                }
                e = true;
                digit = false;
            }
            else
            {
                return false;
            }
        }
        return digit;
    }
};