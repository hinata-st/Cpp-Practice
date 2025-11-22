#include <bits/stdc++.h>

using namespace std;

// question : 一个长度为 n-1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

class mySolution_53_2
{
    public:
    int missingNum(vector<int>& nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j)
        {
            int m = i + (j - i) / 2;
            if (nums[m] > m)
            {
                j = m - 1;
            }
            else
            {
                i = m + 1;
            }
        }
        return i;
    }
};

class offerSolution_53_2
{
public:
    int missingNumber(vector<int> &nums)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] > mid)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    offerSolution_53_2 solution;
    vector<int> nums = {0,1,2,3,4,5,6,7,9};
    int missing_number = solution.missingNumber(nums);
    cout << "The missing number is: " << missing_number << endl;
    return 0;
}
