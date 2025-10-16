#include <bits/stdc++.h>

using namespace std;

// question : 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组[3, 4, 5, 1, 2] 为[1, 2, 3, 4, 5] 的一次旋转，该数组的最小值为1。

class my_Solution
{
    public:
        // 遍历
        int minArray(vector<int> &numbers)
        {
            int min_num = numbers[0];
            int array_size = numbers.size();
            while(array_size > 0)
            {
                min_num = min(min_num, numbers[array_size - 1]);
                array_size--;
            }
            return min_num; 
        }
};

class offer_Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (numbers[mid] > numbers[r])
            {
                l = mid + 1;
            }
            else if (numbers[mid] < numbers[r])
            {
                r = mid;
            }
            else
            {
                --r;
            }
        }
        return numbers[l];
    }
};