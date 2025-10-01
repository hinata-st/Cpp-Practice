#include <bits/stdc++.h>

using namespace std;

/*二分查找(双闭区间)*/
int binarySearch(vector<int> &nums, int target)
{
    int i = 0,j = nums.size() - 1;
    //循环，当搜索区间为空时跳出（当i > j时为空）
    while(i <= j)
    {
        int m = i + (j - i) / 2;//计算中点索引m
        if(nums[m] < target)
        {
            i = m + 1;
        }
        else if(nums[m] > target)
        {
            j = m - 1;
        }
        else
        {
            return m;
        }
    }
    return -1;//未找到目标值，返回-1
}

/*无重复元素的情况*/
// 当数组包含 target 时，插入点的索引就是该 target 的索引。
// 当数组中不存在target时，二分结束时一定有：i指向首个大于 target 的元素，j指向首个小于 target 的元素。易得当数组不包含 target 时，插入索引为 i。

/*二分查找插入点（存在重复元素）*/
int binarySearchInsertion(vector<int> &nums, int target)
{
    int i = 0, j = nums.size() - 1;
    while(i <= j)
    {
        int m = i + (j - i) / 2;
        if(nums[m] < target)
        {
            i = m + 1;//taget在区间[m+1,j]中
        }
        else if(nums[m] > target)
        {
            j = m - 1;//target在区间[i,m-1]中
        }
        else
        {
            j = m - 1; //首个小于target的元素在区间[i,m-1]中
        }
    }
    //返回插入点
    return i;
}

/*查找左边界*/
int binarySearchLeftEdge(vector<int> &nums, int target)
{
    //等价与查找target的插入点
    int i = binarySearchInsertion(nums, target);
    //未找到target，返回-1
    if(i == nums.size() || nums[i] != target)
    {
        return -1;
    }
    //找到target,返回索引i
    return i;
}

/*查找右边界*/
int binarySearchRightEdge(vector<int> &nums,int target)
{
    int i = binarySearchInsertion(nums, target);
    //j指向最右一个target,i指向首个大于target的元素
    int j = i - 1;
    if(j == 0 || nums[j] != target)
    {
        return -1;
    }
    //找到target,返回索引j
    return j;
}

/*转化为查找元素*/
// 我们知道，当数组不包括target时，最终i和j会分别指向首个大于、小与target的元素。
// 查找最左一个target:可以转化为查找target - 0.5,并返回指针i。
// 查找最右一个target:可以转化为查找target + 0.5,并返回指针j。

// Question:给定一个整数数组 nums 和一个目标元素 target ，请在数组中搜索“和”为 target 的两个元素，并返回它们的数组索引。返回任意一个解即可。

/* 方法一：暴力枚举*/
vector<int> twoSumBruteForce(vector<int> &nums,int target)
{
    int size = nums.size();
    //两层循环，时间复杂度为O(n^2)
    for (int i = 0; i < size;i++)
    {
        for (int j = i + 1; j < size;j++)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

/* 方法二：辅助哈希表 */
vector<int> towSumHashTable(vector<int> &nums, int target)
{
    int size = nums.size();
    unordered_map<int, int> dic;
    //单层循环，时间复杂度为O(n)
    for (int i = 0; i < size;i++)
    {
        if(dic.find(target - nums[i]) != dic.end())
        {
            return {dic[target - nums[i]], i};
        }
        dic.emplace(nums[i], i);
    }
    return {};
}

// 普通算法，暴力查找（线性搜索、广度优先搜索、深度优先搜索），时间复杂度较高，通用好；改良版（二分查找、哈希查找、BST/AVL树查找）优化性能，有的需要额外空间开销，如哈希查找，和树查找。哈希查找：查询效率要求高，无序范围的查找；树查找，需要维护顺序大型动态数据。二分查找，大型、有序的数据。