#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

// question :输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构),B是A的子结构， 即 A中有出现和B相同的结构和节点值。

    class mySolution_26
{
    public:
    // root     n
    // left     n/2+1
    // right    n/2+2
    bool treeChildstructure(vector<int> &a, vector<int> &b)
    {
        int treeB_index = 0;
        int i = 0;
        for (i = 0; i < a.size(); i++)
        {
            if (a[i] == b[0])
            {
                treeB_index = i;
                break;
            }
        }
        if(i == a.size())
        {
            return false;
        }
        function<bool(int, int)> dfs = [&](int a_rootindex, int b_rootindex)->bool
        {
            bool root_equal = false;
            if(b_rootindex >= b.size())
            {
                return true;
            }
            else if(a_rootindex >= a.size())
            {
                return false;
            }
            else if(a[a_rootindex] == b[b_rootindex])
            {
                root_equal = true;
            }
            else
            {
                return false;
            }
            bool left = dfs(2 * a_rootindex + 1, 2 * b_rootindex + 1);
            bool right = dfs(2 * a_rootindex + 2, 2 * b_rootindex + 2);
            return left && right && root_equal;
        };
        return dfs(treeB_index, 0);
    }
};

class offerSolution_26
{
public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (!A || !B)
        {
            return false;
        }
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool dfs(TreeNode *A, TreeNode *B)
    {
        if (!B)
        {
            return true;
        }
        if (!A || A->val != B->val)
        {
            return false;
        }
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};
/* 
int main()
{
    mySolution_26 solution;
    vector<int> a = {3,4,5,1,2};
    vector<int> b = {4,1};
    cout << solution.treeChildstructure(a, b) << endl;
    return 0;
} */