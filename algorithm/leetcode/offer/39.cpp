#include <bits/stdc++.h>

using namespace std;

// question : 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。你可以假设数组是非空的，并且给定的数组总是存在多数元素。

class mySolution_39
{
    public:
    int morethanhalfElement(vector<int>& nums)
    {
        int size = nums.size();
        unordered_map<int, int> countMap;
        for (int num : nums)
        {
            countMap[num]++;
            if (countMap[num] > size / 2)
            {
                return num;
            }
        }
        return -1;  
    }
};

class offerSolution_39
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, m = 0;
        for (int &v : nums)
        {
            if (cnt == 0)
            {
                m = v;
                cnt = 1;
            }
            else
                cnt += (m == v ? 1 : -1);
        }
        return m;
    }
};