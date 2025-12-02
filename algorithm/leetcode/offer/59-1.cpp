#include <bits/stdc++.h>

using namespace std;

// question : 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

class mySolution_59_1
{
    public:
    // O(t): O(nk) space: O(k)
    vector<int> maxslidingwindow(vector<int> & nums, int k)
    {
        vector<int> result;
        queue<int> window;
        int max_val = INT_MIN;
        int size = nums.size();
        if (k == 0 || size == 0)
        {
            return result;
        }
        for (int i = 0; i < size; ++i)
        {
            if (i < k)
            {
                window.push(nums[i]);
                max_val = max(max_val, nums[i]);
                if (i == k - 1)
                {
                    result.push_back(max_val);
                }
            }
            else
            {
                int tmep = window.front();
                window.pop();
                window.push(nums[i]);
                max_val = max(max_val, nums[i]);
                if (tmep == max_val)
                {
                    // need to recalculate max_val
                    max_val = INT_MIN;
                    queue<int> temp_queue = window;
                    while (!temp_queue.empty())
                    {
                        max_val = max(max_val, temp_queue.front());
                        temp_queue.pop();
                    }
                }
                result.push_back(max_val);
            }
        }
        return result;
    }
};



class offerSolution_59_1
{
public:
    // O(t): O(n) space: O(k)
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> q;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            // 注意q.front()存储的是最大值的下标
            // 判断队头是否滑出窗口
            if (!q.empty() && i - q.front() + 1 > k)
            {
                q.pop_front();
            }
            // 把比当前元素小的都弹出队列
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            // 然后把当前元素下标加入队列
            q.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};

/*
q = deque()
for i in range(n):
#判断队头是否滑出窗口
    while q and checkout_out(q[0]):
        q.popleft()
    while q and check(q[-1]):
        q.pop()
    q.append(i)*/