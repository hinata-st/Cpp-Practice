#include <bits/stdc++.h>

using namespace std;

// question : 输入一个字符串，打印出该字符串中字符的所有排列.你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

class mySolution_38
{
    public:
        void backtrack(vector<char> &state, const string &choices, vector<bool> &selected, vector<vector<char>> &result)
        {
            if (state.size() == choices.size())
            {
                result.push_back(state);
                return;
            }
            unordered_set<char> duplicated;
            for (int i = 0; i < choices.size(); i++)
            {
                char choice = choices[i];
                if (!selected[i] && duplicated.find(choice) == duplicated.end())
                {
                    state.push_back(choice);
                    //重复选择剪枝：整个搜索过程中只有一个 selected 。它记录的是当前状态中包含哪些元素，其作用是避免某个元素在 state 中重复出现。
                    selected[i] = true;
                    //相等元素剪枝：每轮选择（每个调用的 backtrack 函数）都包含一个 duplicated 。它记录的是在本轮遍历（for 循环）中哪些元素已被选择过，其作用是保证相等元素只被选择一次。   
                    duplicated.emplace(choice);
                    backtrack(state, choices, selected, result);
                    state.pop_back();
                    selected[i] = false;
                }
            }
    }
    vector<vector<char>> permute(const string &choices)
    {
        vector<char> state;
        vector<bool> selected(choices.size(), false);
        vector<vector<char>> result;
        backtrack(state, choices, selected, result);
        return result;
    }
};

class offerSolution_38
{
public:
    vector<string> permutation(string s)
    {
        vector<string> ans;
        function<void(int)> dfs = [&](int i)
        {
            if (i == s.size() - 1)
            {
                ans.push_back(s);
                return;
            }
            unordered_set<char> vis;
            for (int j = i; j < s.size(); ++j)
            {
                if (!vis.count(s[j]))
                {
                    vis.insert(s[j]);
                    swap(s[i], s[j]);
                    dfs(i + 1);
                    swap(s[i], s[j]);
                }
            }
        };
        dfs(0);
        return ans;
    }
};