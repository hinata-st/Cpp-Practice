#include <bits/stdc++.h>

using namespace std;

// question :

class mySolution_56_1
{
    public:
    //O(t): O(n) space: O(n)
    vector<int> singleNumbers(vector<int>& nums)
    {
        unordered_map<int, int> hash_map;
        for (const int &num : nums)
        {
            hash_map[num]++;
        }
        vector<int> result;
        for (const auto &entry : hash_map)
        {
            if (entry.second == 1)
            {
                result.push_back(entry.first);
            }
        }
        return result;
    }
};

class offerSolution_56_1
{
public:
    // note: use bit manipulation
    // a ^ a = 0, a ^ 0 = a,a ^ b ^ c = a ^ (b ^ c)
    //O(t): O(n) space: O(1)
    vector<int> singleNumbers(vector<int> &nums)
    {
        int xs = 0;
        // eg : nums = [1,2,10,4,1,4,3,3]
        for (int &x : nums)
        {
            // xs = 1 ^ 2 ^ 10 ^ 4 ^ 1 ^ 4 ^ 3 ^ 3 
            // = (1 ^ 1) ^ (4 ^ 4) ^ (3 ^ 3) ^ 2 ^ 10
            // = 0 ^ 0 ^ 0 ^ 2 ^ 10 = 2 ^ 10
            // 1000 (8)
            xs ^= x;
        }
        // lb : least bit that is 1
        int lb = xs & -xs;
        int a = 0;
        for (int &x : nums)
        {
            if (x & lb)// 将a and b 分到不同的组
            {
                // 对这个组的所有数字进行异或，成对的数字抵消为 0，最终剩下的就是 A
                a ^= x;// a = 10
            }
        }
        // xs = a ^ b, know a, get b, xs ^ a = (a ^ b) ^ a = b
        int b = xs ^ a;// b = 2
        return {a, b};
    }
};