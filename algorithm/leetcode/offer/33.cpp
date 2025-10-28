#include <bits/stdc++.h>

using namespace std;

// question :

class mySolution_33
{
    public:
    bool isPostorder(vector<int>& sequence)
    {
        int last = sequence.size() - 1;
        // 找不到根节点与左右子树节点的关系

    }

};

// 思路：找到第一个大于根节点的位置i,那么i右边的元素都应该大于根节点，否则返回false。

class offerSolution_33
{
    public:
    bool verifyPostoder(vector<int>& postorder)
    {
        function<bool(int, int)> dfs = [&](int l, int r) -> bool
        {
            if(l >= r)
            {
                return true;
            }
            int v = postorder[r];
            int i = l;
            // 找到第一个大于根节点的位置i  
            while(i < r && postorder[i] < v)
            {
                ++i;
            }
            // 检查i右边的元素是否都大于根节点
            for (int j = i; j < r; ++j)
            {
                if (postorder[j] < v)
                {
                    return false;
                }
            }
            // 递归检查左子树区间和右子树区间
            return dfs(l , i - 1) && dfs(i, r - 1);
        };
        return dfs(0, postorder.size() - 1);
    }
};