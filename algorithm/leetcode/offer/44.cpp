#include <bits/stdc++.h>

using namespace std;

// question : 

class mySoulution_44
{
    public:
        int nPositonNumber(int n)
        {
            int k = 1, cnt = 9;
            while(1ll * k * cnt < n)
            {
                n -= k * cnt;
                k++;
                cnt *= 10;
            }
            int num = pow(10, k - 1) + (n - 1) / k;
            int idx = (n - 1) % k;
            return to_string(num)[idx] - '0';
        }
};