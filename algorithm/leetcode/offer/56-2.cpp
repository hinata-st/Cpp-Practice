#include <bits/stdc++.h>

using namespace std;

// question : 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

class mySolution_56_2
{
    public:
    // O(t) = O(n), O(s) = O(n)
    int singleNumber_hash(vector<int>& nums)
    {
        unordered_map<int, int> hash_map;
        for (const int num : nums)
        {
            hash_map[num]++;
        }
        for (const auto val : hash_map)
        {
            if (val.second == 1)
            {
                return val.first;
            }
        }
        return -1; // or throw an exception if no single number is found
    }
    int singleNumber_bit(vector<int>& nums)
    {
        int result = 0;
        int a[32] = {0};
        for (const int num : nums)
        {
            for (int i = 0; i < 32; ++i)
            {
                a[i] += (num >> i) & 1;
            }
        }
        for (int i = 0; i < 32; ++i)
        {
            if (a[i] % 3 != 0)
            {
                result |= (1 << i);
            }
        }
        return result;
    }
};

class offerSolution_56_2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int cnt[32]{};
        for (int &x : nums)
        {
            for (int i = 0; i < 32; ++i)
            {
                cnt[i] += x & 1;
                x >>= 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (cnt[i] % 3)
            {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};