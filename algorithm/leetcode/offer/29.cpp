#include <bits/stdc++.h>

using namespace std;

// question : 

class mySolution_29
{
    public:
        void printmatrix(vector<vector<int>> &matrix)
        {
            if (matrix.size() == 0)
            {
                return;
            }
            int n = matrix.size();
            int m = matrix[0].size();
            vector<int> dir = {1, 0, 0, 1, -1, 0, 0, -1};// right, down, left, up
            int direction = 0;
            int count = n * m;
            int x = 0, y = 0;
            int visited[n][m];
            memset(visited, 0, sizeof(visited));
            while(1)
            {
                cout << matrix[y][x] << " ";
                count--;
                if (count == 0)
                {
                    return;
                }
                visited[y][x] = 1;
                while (x + dir[2 * direction] >= m || y + dir[2 * direction + 1] >= n || x + dir[2 * direction] < 0 || y + dir[2 * direction + 1] < 0 || visited[y + dir[2 * direction + 1]][x + dir[2 * direction]] == 1)
                {
                    direction = (direction + 1) % 4;
                }
                x += dir[2 * direction];
                y += dir[2 * direction + 1];
            }
        }
};

class offerSolution_29
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        bool vis[m][n];
        memset(vis, false, sizeof vis);
        int i = 0, j = 0, k = 0;
        int dirs[5] = {0, 1, 0, -1, 0};
        vector<int> ans(m * n);
        for (int h = 0; h < m * n; ++h)
        {
            ans[h] = matrix[i][j];
            vis[i][j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y])
            {
                k = (k + 1) % 4;
                x = i + dirs[k];
                y = j + dirs[k + 1];
            }
            i = x;
            j = y;
        }
        return ans;
    }
};

/* int main()
{
    mySolution_29 mysolu;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    mysolu.printmatrix(matrix);
    return 0;
} */