#include <bits/stdc++.h>

using namespace std;

// 插入排序的工作原理：开启一个循环，每轮将未排序区间的首个元素插入到已排序区间的合适位置
/* 插入排序 */
void insertionSort(vector<int> &nums)
{
    // 外循环：已排序区间为[0, i - 1]
    for (int i = 1; i < nums.size(); i++)
    {
        int base = nums[i], j = i - 1;
        // 内循环：将 base 插入到已排序区间[0 , i - 1] 中合适的位置
        while (j >= 0 && nums[j] > base)
        {
            nums[j + 1] = nums[j]; // 将 nums[j] 向右移动一位
            j--;
        }
        nums[j + 1] = base; // 将 base 插入到正确位置
    }
}