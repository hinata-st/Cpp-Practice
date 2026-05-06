#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int left = 0;
        int right = plants.size() - 1;
        int count = 0;
        int now_capa_A = capacityA;
        int now_capa_B = capacityB;
        while (left < right)
        {
            if (now_capa_A >= plants[left])
            {
                left++;
                now_capa_A -= plants[left];
            }
            else if (now_capa_A < plants[left])
            {
                count++;
                now_capa_A = capacityA - plants[left];
                left++;
            }
            if (now_capa_B >= plants[right])
            {
                right--;
                now_capa_B -= plants[right];
            }
            else if (now_capa_B < plants[right])
            {
                count++;
                now_capa_B = capacityB - plants[right];
                right--;
            }
        }
        if ((max(now_capa_A, now_capa_B) < plants[left]) && (left == right))
        {
            count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> plants = {3, 4, 6, 6, 5};
    int capacityA = 7;
    int capacityB = 6;
    cout << s.minimumRefill(plants, capacityA, capacityB) << endl;
    return 0;
}