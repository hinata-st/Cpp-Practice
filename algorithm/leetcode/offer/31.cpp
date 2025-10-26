#include <bits/stdc++.h>

using namespace std;

// question : 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

class mySolution_31
{
    public : 
    bool isPopOrder(vector<int> &push, vector<int> &pop)
    {
        std::size_t n = push.size();
        std::size_t m = pop.size();
        if (n != m)
        {
            return false;
        }
        stack<int> stk;
        int j = 0;
        for (const auto& v : push)
        {
            stk.push(v);
            while (!stk.empty() && stk.top() == pop[j])
            {
                stk.pop();
                ++j;
            }
        }
        return j == n;
    }
};

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> stk;
        int j = 0;
        for (int v : pushed)
        {
            stk.push(v);
            while (!stk.empty() && stk.top() == popped[j])
            {
                stk.pop();
                ++j;
            }
        }
        return j == pushed.size();
    }
};
/* 
int main()
{
    mySolution_31 sol;
    vector<int> push = {1,2,3,4,5};
    vector<int> pop_1 = {4,5,3,2,1};
    vector<int> pop_2 = {4,3,5,1,2};
    bool res_1 = sol.isPopOrder(push, pop_1);
    bool res_2 = sol.isPopOrder(push, pop_2);
    cout << res_1 << endl;
    cout << res_2 << endl;
    return 0;
} */