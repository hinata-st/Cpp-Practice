#include <bits/stdc++.h>

using namespace std;

// question : 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

class My_solution_12
{
    int rows, cols;

    public:
    string exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        cols = board[0].size();
        vector<char> state;
        vector<char> res;
        vector<vector<bool>> selected(rows, vector<bool>(cols, false));
        backtrack(board, res, state, word, 0, 0, selected);
        /*for (auto c : res)
        {
            cout << c << " ";
        }*/
        return res.size() == word.size() ? "true" : "false";
    }
    private:
        void backtrack(vector<vector<char>> &board, vector<char> &res, vector<char> &state, string word, int x, int y, vector<vector<bool>> &selected)
        {
            // 状态长度等于元素数量时，记录解
            if (state.size() == word.size())
            {
                res = state;
                return;
            }
            // 遍历所有选择
            vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto dir : directions)
            {
                // 剪枝：不允许重复选择元素,且 不允许重复选择相等的元素
                if (x >= 0 && x < rows && y >= 0 && y < cols && !selected[x][y] && board[x][y] == word[state.size()])
                {
                    // 尝试：做出选择，更新状态
                    state.push_back(board[x][y]);
                    selected[x][y] = true;
                    // 进行下一轮选择
                    backtrack(board, res, state, word, x + dir[0], y + dir[1], selected);
                    // 回退：撤销选择，恢复到之前的状态
                    state.pop_back();
                    selected[x][y] = false;
                }
            }
    }
};

class offer_Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool
        {
            if (k == word.size())
            {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
            {
                return false;
            }
            board[i][j] = '.';
            bool ans = 0;
            for (int l = 0; l < 4; ++l)
            {
                ans |= dfs(i + dirs[l], j + dirs[l + 1], k + 1);
            }
            board[i][j] = word[k];
            return ans;
        };
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class My_solution_12_Fixed
{
    int rows, cols;

public:
    bool exist(vector<vector<char>> &board, string word) // ✅ 返回 bool
    {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> selected(rows, vector<bool>(cols, false));

        // ✅ 遍历所有起点
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (backtrack(board, word, 0, i, j, selected))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>> &board, string &word, int k,
                   int x, int y, vector<vector<bool>> &selected)
    {
        // 终止条件
        if (k == word.size())
        {
            return true;
        }

        // 剪枝：边界 + 访问 + 匹配
        if (x < 0 || x >= rows || y < 0 || y >= cols ||
            selected[x][y] || board[x][y] != word[k])
        {
            return false;
        }

        // 标记访问
        selected[x][y] = true;

        // 四个方向
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto &dir : directions)
        {
            if (backtrack(board, word, k + 1, x + dir[0], y + dir[1], selected))
            {
                return true;
            }
        }

        // 回溯
        selected[x][y] = false;
        return false;
    }
};

int main()
{
    My_solution_12 solu;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << solu.exist(board, word) << endl;
    return 0;
}