#include <bits/stdc++.h>

using namespace std;

vector<int> maxHeap; // 大顶堆数组表示

/* 访问堆顶元素*/
int peek()
{
    return maxHeap[0];
}

/* 元素入堆 */
void push(int val)
{
    // 添加节点
    maxHeap.push_back(val);
    // 从底至顶堆化
    siftUp(size() - 1);
}

int size()
{
    return maxHeap.size();
}

int parent(int i)
{
    return (i - 1) / 2;
} 

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

/* 从节点 i 开始，从底至顶堆化 */
void siftUp(int i)
{
    while(true)
    {
        // 获取节点 i 的父节点
        int p = parent(i);
        // 当“越过节点”或“节点无须修复”时，结束堆化
        if(p < 0 || maxHeap[i] <= maxHeap[p])
        {
            break;
        }
        // 交换两节点
        swap(maxHeap[i], maxHeap[p]);
        // 循环向上堆化
        i = p;
    }
}

/* 从节点 i 开始，从顶至底堆化 */
void siftDown(int i)
{
    while(true)
    {
        // 判断节点 i, l, r 中至最大的节点,记为 ma
        int l = left(i), r = right(i), ma = i;
        if(l < size() && maxHeap[l] > maxHeap[ma])
        {
            ma = l;
        }
        if(r < size() && maxHeap[r] > maxHeap[ma])
        {
            ma = r;
        }
        // 若节点 i 最大索引 l, r越界，则无须继续堆化，跳出
        if(ma == i)
        {
            break;
        }
        if(ma == i)
        {
            break;
        }
        swap(maxHeap[i], maxHeap[ma]);
        // 循环向下堆化
        i = ma;
    }
}

/* 构造方法，根据输入列表建堆 */
void MaxHeap(vector<int> nums)
{
    // 将列表元素原封不动添加进堆
    maxHeap = nums;
    // 堆化除叶节点以外的其他所有节点
    for (int i = parent(size() - 1); i >= 0; i--)
    {
        siftDown(i);
    }
}