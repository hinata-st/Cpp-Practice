#include <bits/stdc++.h>

using namespace std;

/* 基于邻接矩阵实现的无向图类 */
class GraphAdjMat
{
    vector<int> vertices;              // 顶点列表,元素代表“顶点值”，索引代表“顶点索引”
    vector<vector<int>> adjMat;        // 邻接矩阵,行列索引对应“顶点索引”

    public:
        /* 构造方法 */
        GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges)
        {
            // 添加顶点
            for (int val : vertices)
            {
                addVertex(val);
            }
            // 添加边
            // 请注意, edges 元素代表顶点索引, 即对应 vertices 元素索引
            for (const vector<int> &edge : edges)
            {
                addEdge(edge[0],edge[1]);
            }
        }

        /* 获取顶点数量 */
        int size() const
        {
            return vertices.size();
        }

        /* 添加顶点 */
        void addVertex(int val)
        {
            int n = size();
            // 向顶点列表中添加新顶点的值
            vertices.push_back(val);
            // 在邻接矩阵中添加一行
            adjMat.emplace_back(vector<int>(n, 0));
            // 在邻接矩阵中添加一列
            for (vector<int> &row : adjMat)
            {
                row.push_back(0);
            }
        }

        /* 删除顶点 */
        void removeVertex(int index)
        {
            if(index >= size())
            {
                throw out_of_range("顶点不存在");
            }
            // 在顶点列表中移除索引 index 的顶点
            vertices.erase(vertices.begin() + index);
            // 在邻接矩阵中删除索引 index 的行
            adjMat.erase(adjMat.begin() + index);
            // 在邻接矩阵中删除索引 index 的列
            for (vector<int> &row : adjMat)
            {
                row.erase(row.begin() + index);
            }
        }

        /* 添加边 */
        // 参数 i, j 对应 vertices 元素索引
        void addEdge(int i,int j)
        {
            // 索引越界与相等处理
            if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
            {
                throw out_of_range("顶点不存在");
            }
            // 在无向图中，邻接矩阵关于对角线对称，既满足 (i,j) == (j,i)
            adjMat[i][j] = 1;
            adjMat[j][i] = 1;
        }

        /* 删除边 */
        void removeEdge(int i, int j)
        {
            // 索引越界与相等处理
            if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
            {
                throw out_of_range("顶点不存在");
            }
            adjMat[i][j] = 0;
            adjMat[j][i] = 0;
        }

        void printVector(const vector<int> &vec)
        {
            cout << "[";
            for (int i = 0; i < vec.size(); i++)
            {
                cout << vec[i];
                if (i != vec.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }

        void printVectorMatrix(const vector<vector<int>> &mat)
        {
            cout << "[";
            for (int i = 0; i < mat.size(); i++)
            {
                cout << "  [";
                for (int j = 0; j < mat[i].size(); j++)
                {
                    cout << mat[i][j];
                    if (j != mat[i].size() - 1)
                    {
                        cout << ", ";
                    }
                }
                cout << "]";
                if (i != mat.size() - 1)
                {
                    cout << "," << endl;
                }
            }
            cout << "]" << endl;
        }

        /* 打印邻接矩阵 */
        void print()
        {
            cout << "顶点列表 = ";
            printVector(vertices);
            cout << "邻接矩阵 = " << endl;
            printVectorMatrix(adjMat);
        }
};