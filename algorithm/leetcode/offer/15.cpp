#include <bits/stdc++.h>

using namespace std;    

class My_solution_15
{
    public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while(n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};

int main()
{
    My_solution_15 solu;
    uint32_t n;
    cin >> n;
    cout << solu.hammingWeight(n) << endl;
    return 0;
}

class offer_Solution_1
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            n &= (n - 1);
            ++ans;
        }
        return ans;
    }
};

class offer_Solution_2
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            n -= n & -n;
            ++ans;
        }
        return ans;
    }
};