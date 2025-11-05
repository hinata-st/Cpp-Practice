#include <bits/stdc++.h>

using namespace std;

// question : 

class mySolution_40
{
    public:
    vector<int> getsmallestK(vector<int>& arr, int k)
    {
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

class offerSolution_40
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        priority_queue<int> q;
        for (int &x : arr)
        {
            q.push(x);
            if (q.size() > k)
            {
                q.pop();
            }
        }
        vector<int> ans(k);
        for (int i = 0; i < k; ++i)
        {
            ans[i] = q.top();
            q.pop();
        }
        return ans;
    }
};