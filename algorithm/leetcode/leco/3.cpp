#include <bits/stdc++.h>

using namespace std;

// question :

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.empty())
            return {};
        unordered_map<string, vector<string>> mp;
        for (auto &s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].emplace_back(s);
        }
        vector<vector<string>> result;
        for (auto &p : mp)
        {
            result.emplace_back(move(p.second));
        }
        return result;
    }
};