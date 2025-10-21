// questions: 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

#include <bits/stdc++.h>

using namespace std;

string replaceSpace(const string &s)
{
    string res;
    for (char c : s)
    {
        if (c == ' ')
            res += "%20";
        else
            res += c;
    }
    return res;
}


// int main()
// {
//     string s;
//     getline(cin, s);
//     cout << replaceSpace(s) << endl;
//     return 0;
// }