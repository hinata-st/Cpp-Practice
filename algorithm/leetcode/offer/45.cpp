#include <bits/stdc++.h>

using namespace std;

// question : 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

class offerSolution_45
{
    public:
    string minNumber(vector<int> &nums)
    {
        vector<string> arr;
        for (int& x : nums)
        {
            arr.emplace_back(to_string(x));
        }
        sort(arr.begin(), arr.end(), [](const string& a, const string& b)
             {
                 return a + b < b + a;
             });
        string ans;
        for (auto& x : arr)
        {
            ans += x;
        }
        return ans; 
    }
};
