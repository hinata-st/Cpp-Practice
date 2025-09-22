#include <bits/stdc++.h>

using namespace std;

void numbs_change(int *numb1,int *numb2)
{
    int temp = *numb2;
    *numb2 = *numb1;
    *numb1 = temp;
}

#if 1

int main()
{
    int numb1, numb2;
    cin >> numb1 >> numb2;
    numbs_change(&numb1, &numb2);
    cout << numb1 << ' '<< numb2 << endl;
    return 0;
}
//5.7
#endif

#if 0
int main()
{
    char ch;
    while(cin >> ch)
    {
        switch (ch)
        {
        case 'a':
            cout << "a" << endl; 
        case 'b':
            cout << "b" << endl;
        case 'c':
            cout << "c" << endl;
        case 'd':
            cout << "d" << endl;
        case 'e':
            cout << "e" << endl;
            break;
        }
    }
}
#endif

//5.14 记录最大单词的重复次数
#if 0
int main()
{
    string str;
    string last_str;
    string max_str;
    int cnt = 0;
    int first = 0;
    int max_cnt = 0;
    while(cin >> str)
    {
        
        if(first == 0)
        {
            first = 1;
        }
        else
        {
            if(str == last_str)
            {
                cnt++;
            }    
            else
            {
                cnt = 1;
            }
        }
        if(cnt > max_cnt)
        {
            max_cnt = cnt;
            max_str = str;
        }
        last_str = str;
    }
    cout << max_str << max_cnt << endl;
}
#endif