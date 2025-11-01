#include <bits/stdc++.h>

using namespace std;

// question : 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

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

class mySolution_33_2
{
    public:
        bool isPostorder(vector<int> &sequence) 
        {
            function<bool(int, int)> verify = [&](int left, int right) -> bool 
            {
                if (left >= right)
                {
                    return true;
                }
                int root = sequence[right];
                int rightRootIndex = left;
                // 找到第一个大于根节点的位置
                for (auto i = left; i < right; ++i)
                {
                    if (sequence[i] > root)
                    {
                        rightRootIndex = i;
                        break;
                    }
                }
                // 检查右子树的节点是否都大于根节点
                for (auto i = rightRootIndex; i < right; ++i)
                {
                    if (sequence[i] < root)
                    {
                        return false;
                    }
                }
                return verify(left, rightRootIndex - 1) && verify(rightRootIndex, right - 1);
            };
            return verify(0, sequence.size() - 1);
        }
};

/* int main()
{
    vector<int> sequence1 = {1, 6, 3, 2, 5};
    vector<int> sequence2 = {1, 3, 2, 6, 5};
    offerSolution_33 test;
    bool res1 = test.verifyPostoder(sequence1);
    bool res2 = test.verifyPostoder(sequence2);
    cout << res1 << endl;
    cout << res2  << endl;
    return 0;
} */