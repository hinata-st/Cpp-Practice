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
                    selected[i] = true;
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