#include <bits/stdc++.h>

using namespace std;

// questoin : 

class mySolution_51
{
    public:
    int reversePairs(vector<int> &nums)
    {
        int size = nums.size();
        long count = 0;
        if(size == 0)
        {
            return 0;
        }
        function<void(vector<int> &, int, int, int)> merge = [&](vector<int> &nums, int left, int mid, int right) -> void
        {
            // 左子数组区间为 [left, mid], 右子数组区间为 [mid+1, right]
            // 创建一个临时数组 tmp ，用于存放合并后的结果
            vector<int> tmp(right - left + 1);
            // 初始化左子数组和右子数组的起始索引
            int i = left, j = mid + 1, k = 0;
            // 当左右子数组都还有元素时，进行比较并将较小的元素复制到临时数组中
            while (i <= mid && j <= right)
            {
                if (nums[i] <= nums[j])
                    tmp[k++] = nums[i++];
                else
                {
                    tmp[k++] = nums[j++];
                    count += mid - i + 1;
                }
            }
            // 将左子数组和右子数组的剩余元素复制到临时数组中
            while (i <= mid)
            {
                tmp[k++] = nums[i++];
            }
            while (j <= right)
            {
                tmp[k++] = nums[j++];
            }

            // 将临时数组 tmp 中的元素复制回原数组 nums 的对应区间
            for (k = 0; k < tmp.size(); k++)
            {
                nums[left + k] = tmp[k];
            }
        };
        function<void(vector<int> &,int, int)> merge_sort = [&](vector<int> &nums, int left, int right) -> void
        {

            // 终止条件
            if (left >= right)
                return; // 当子数组长度为 1 时终止递归
            // 划分阶段
            int mid = left + (right - left) / 2; // 计算中点
            merge_sort(nums, left, mid);         // 递归左子数组
            merge_sort(nums, mid + 1, right);    // 递归右子数组
            // 合并阶段
            merge(nums, left, mid, right);
        };
        merge_sort(nums, 0, size - 1);
        return count;
    }
};

class offerSolution_51
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int t[n];
        function<int(int, int)> mergeSort = [&](int l, int r) -> int
        {
            if (l >= r)
            {
                return 0;
            }
            int mid = (l + r) >> 1;
            int ans = mergeSort(l, mid) + mergeSort(mid + 1, r);
            int i = l, j = mid + 1, k = 0;
            while (i <= mid && j <= r)
            {
                if (nums[i] <= nums[j])
                {
                    t[k++] = nums[i++];
                }
                else
                {
                    ans += mid - i + 1;
                    t[k++] = nums[j++];
                }
            }
            while (i <= mid)
            {
                t[k++] = nums[i++];
            }
            while (j <= r)
            {
                t[k++] = nums[j++];
            }
            for (i = l; i <= r; ++i)
            {
                nums[i] = t[i - l];
            }
            return ans;
        };
        return mergeSort(0, n - 1);
    }
};

