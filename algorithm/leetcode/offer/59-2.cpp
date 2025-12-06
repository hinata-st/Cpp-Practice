#include <bits/stdc++.h>

using namespace std;

// question : 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

class mySolution_59_2
{
    private:
    queue<int> max_queue;
    public:
    void push_back(int value)
    {
        max_queue.push(value);
    }
    int pop_front()
    {
        if (max_queue.empty())
        {
            return -1;
        }
        return max_queue.front();
    }
    int max_value()
    {
        if (max_queue.empty())
        {
            return -1;
        }

    }
};

class MaxQueue
{
public:
    MaxQueue()
    {
    }

    int max_value()
    {
        return q2.empty() ? -1 : q2.front();
    }

    void push_back(int value)
    {
        while (!q2.empty() && q2.back() < value)
        {
            q2.pop_back();
        }
        q1.push(value);
        q2.push_back(value);
    }

    int pop_front()
    {
        if (q1.empty())
        {
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        // 只管弹出的是不是最大值
        if (q2.front() == ans)
        {
            q2.pop_front();
        }
        return ans;
    }

private:
    queue<int> q1;
    deque<int> q2;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

class mySolutoin_59_2_v2
{
    private:
        queue<int> q1;
        deque<int> q2;
    public:
        int max_value()
        {
            if (q2.empty())
            {
                return -1;
            }
            return q2.front();
        }
        int push_back(int value)
        {
            q1.push(value);
            while (!q2.empty() && q2.back() < value)
            {
                q2.pop_back();
            }
            q2.push_back(value);
        }
        int pop_front()
        {
            if (q1.empty())
            {
                return -1;
            }
            int ans = q1.front();
            q1.pop();
            if (ans == q2.front())
            {
                q2.pop_front();
            }
            return ans;
        }
};