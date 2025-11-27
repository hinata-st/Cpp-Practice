#include <bits/stdc++.h>

using namespace std;

// question : 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

class offerSolution_57_2
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> ans;
        int l = 1, r = 2;
        while (l < r)
        {
            int s = (l + r) * (r - l + 1) / 2;
            if (s == target)
            {
                vector<int> t(r - l + 1);
                iota(t.begin(), t.end(), l);
                ans.emplace_back(t);
                ++l;
            }
            else if (s < target)
            {
                ++r;
            }
            else
            {
                ++l;
            }
        }
        return ans;
    }
};