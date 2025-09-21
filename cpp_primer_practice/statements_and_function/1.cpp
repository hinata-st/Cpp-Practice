#include <bits/stdc++.h>

using namespace std;

//使用if else 语句实现；把数字转换为字母成绩的要求
#if 0

int main()
{
    int core;
    cout << "请输入一串成绩数字：" << endl;
    while(cin >> core)
    {
        if(core >= 90)
            cout << "A" << endl;
        else if(core >= 80)
            cout << "B" << endl;
        else if(core >= 70)
            cout << "C" << endl;
        else if(core >= 60)
            cout << "D" << endl;
        else
            cout << "E" << endl;
        cout << "请输入一串成绩数字：" << endl;
    }
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
#if 1
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