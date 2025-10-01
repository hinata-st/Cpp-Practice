// question:在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include <bits/stdc++.h>

//方法一：二分查找

using namespace std;

bool search(vector<int> &cols,int target)
{
    int i = 0,j = cols.size() - 1;
    while(i<=j)
    {
        int mid = i + (j - i) / 2;
        if(cols[mid] == target)
            return true;
        else if(cols[mid] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target;
    cin >> target;
    int rows = matrix.size();
    if(rows == 0)
    {
        cout << "false" << endl;
        return 0;
    }
    int cols = matrix[0].size();
    for(int i = 0; i < rows;i++)
    {
        if(search(matrix[i], target))
        {
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
    return 0;
}

// lower_bound 是 C++ STL 中用于二分查找的算法，能在有序区间内快速找到第一个不小于 target 的元素的位置。

class Solution
{
    public:
        bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
        {
            for(auto &row : matrix)
            {
                int j = lower_bound(row.begin(), row.end(), target) - row.begin();
                if(j < matrix[0].size() && row[j] == target)
                {
                    return true;
                }
            }
            return false;
        }
};

// 方法二：从左下角或右上角搜索
class Solution2
{
    public:
        bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
        {
            if(matrix.empty())
            {
                return false;
            }
            int m = matrix.size(),n = matrix[0].size();
            int i = m - 1,j = 0;
            while(i < m && j >= 0)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
                else if(matrix[i][j] < target)
                {
                    i++;
                }
                else
                {
                    --j; 
                }
            }
            return false;
        }
};