#include <bits/stdc++.h>

using namespace std;

class RangeFreqQuery
{
private:
    vector<int> arr_pri;

public:
    RangeFreqQuery(vector<int> &arr)
    {
        arr_pri = arr;
    }

    int query(int left, int right, int value)
    {
        int cnt = 0;
        vector<int> temp(arr_pri.begin() + left, arr_pri.begin() + right + 1);
        sort(temp.begin(), temp.end());
        auto it = lower_bound(temp.begin(), temp.end(), value);
        while (it != temp.end() && *it == value)
        {
            cnt++;
            it++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> arr = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery *obj = new RangeFreqQuery(arr);
    int param_1 = obj->query(1, 2, 4);
    cout << param_1 << endl;
    return 0;
}