#include <bits/stdc++.h>

using namespace std;

// question :给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int size = height.size();
        if (size < 3)
        {
            return 0;
        }
        vector<int> left_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        vector<int> right_max(size);
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i > -1; i--)
        {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        unsigned int sum = 0;
        for (int i = 0; i < size - 1; i++)
        {
            sum += min(right_max[i], left_max[i]) - height[i];
        }
        return sum;
    }
};