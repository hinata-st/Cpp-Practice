#include <bits/stdc++.h>

using namespace std;

// question :

class mySolution_66
{
    public:
    vector<int> buildMulMatir(vector<int> a)
    {
        int size = a.size();
        vector<int> b(size, 1);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i != j)
                {
                    b[i] = b[i] * a[j];
                }
                else
                {
                    continue;
                }
            }
        }
        return b;
    }
};

class offerSolution_66
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans(n);
        for (int i = 0, left = 1; i < n; ++i)
        {
            ans[i] = left;
            left *= a[i];
        }
        for (int i = n - 1, right = 1; ~i; --i)
        {
            ans[i] *= right;
            right *= a[i];
        }
        return ans;
    }
};

int main()
{
    mySolution_66 solution;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> result = solution.buildMulMatir(a);
    cout << endl;
    cout << "The product array is: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
