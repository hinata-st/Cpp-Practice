#include <bits/stdc++.h>

using namespace std;

// question :

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