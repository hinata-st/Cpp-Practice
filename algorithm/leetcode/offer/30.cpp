#include <bits/stdc++.h>

using namespace std;

// question : 

class myMinStack
{
    stack<int> dataStack;
    stack<int> minStack;
    public:
    myMinStack()
    {
        
    }
    void push(int x)
    {
        dataStack.push(x);
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }
    void pop()
    {
        if (dataStack.top() == minStack.top())
        {
            minStack.pop();
        }
        dataStack.pop();
    }
    int top()
    {
        return dataStack.top();
    }
    int min()
    {
        return minStack.top();
    }
};

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        stk2.push(INT_MAX);
    }

    void push(int x)
    {
        stk1.push(x);
        stk2.push(min(x, stk2.top()));
    }

    void pop()
    {
        stk1.pop();
        stk2.pop();
    }

    int top()
    {
        return stk1.top();
    }

    int getMin()
    {
        return stk2.top();
    }

private:
    stack<int> stk1;
    stack<int> stk2;
};