#include <bits/stdc++.h>

using namespace std;

/* 移动一个圆盘 */
void move(vector<int> &src, vector<int> &tar, const string &srcName, const string &tarName)
{
    // 从 src 顶部拿出一个圆盘
    int pan = src.back();
    src.pop_back();
    // 将圆盘放入 tar 顶部
    tar.push_back(pan);
    // 输出移动过程
    cout << "移动圆盘 " << pan << " 从 " << srcName << " -> " << tarName << endl;
}

/* 求解汉诺塔问题 f(i) */
void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar, 
         const string &srcName, const string &bufName, const string &tarName)
{
    // 若 src 只剩下一个圆盘，则直接将其移动到 tar
    if(i == 1)
    {
        move(src, tar, srcName, tarName);
        return;
    }
    // 子问题f(i - 1) : 将 src 顶部 i - 1 个圆盘借助 tar 移动到 buf
    dfs(i - 1, src, tar, buf, srcName, tarName, bufName);
    // 子问题 f(1) : 将 src 剩余一个圆盘移到 tar
    move(src, tar, srcName, tarName);
    // 子问题 f(i - 1) : 将 buf 顶部 i - 1 个圆盘借助 src 移动到 tar
    dfs(i - 1, buf, src, tar, bufName, srcName, tarName);
}

/* 求解汉诺塔问题 */
void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n = A.size();
    // 将 A 顶部 n 个圆盘借助 B 移动到 C
    dfs(n, A, B, C, "A", "B", "C");
}

int main()
{
    vector<int> A = {5, 4, 3, 2, 1, 0}, B, C;
    
    cout << "初始状态:" << endl;
    cout << "A: "; for(int x : A) cout << x << " "; cout << endl;
    cout << "B: "; for(int x : B) cout << x << " "; cout << endl;
    cout << "C: "; for(int x : C) cout << x << " "; cout << endl;
    cout << "\n开始移动:\n" << endl;
    
    hanota(A, B, C);
    
    cout << "\n最终状态:" << endl;
    cout << "A: "; for(int x : A) cout << x << " "; cout << endl;
    cout << "B: "; for(int x : B) cout << x << " "; cout << endl;
    cout << "C: "; for(int x : C) cout << x << " "; cout << endl;
    
    return 0;
}