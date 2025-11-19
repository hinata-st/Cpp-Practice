#include <bits/stdc++.h>

using namespace std;

// question :在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

class mySolution_50
{
    public:
    char firstUniqChar(string s)
    {
        if (s.size() == 0)
            return ' ';
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        for (char c : s)
        {
            if (mp[c] == 1)
                return c;
        }
        return ' ';
    }
};

class offerSolution_50
{
public:
    char firstUniqChar(string s)
    {
        int cnt[26]{};
        for (char &c : s)
        {
            ++cnt[c - 'a'];
        }
        for (char &c : s)
        {
            if (cnt[c - 'a'] == 1)
            {
                return c;
            }
        }
        return ' ';
    }
};