#include <bits/stdc++.h>

using namespace std;

// question :

class mySolution_48
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> mp;
        int left = 0, right = 0;
        int ans = 0;
        while (right < s.size())
        {
            if (mp.find(s[right]) == mp.end())
            {
                mp.insert(s[right]);
                right++;
                ans = max(ans, right - left);
            }
            else
            {
                mp.erase(s[left]);
                left++;
            }
        }

        return ans;
    }
};

class offerSolution_48
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        unordered_set<char> vis;
        for (int i = 0, j = 0; i < s.size(); ++i)
        {
            while (vis.count(s[i]))
            {
                vis.erase(s[j++]);
            }
            vis.insert(s[i]);
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};