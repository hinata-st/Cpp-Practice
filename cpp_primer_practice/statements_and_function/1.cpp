#include <iostream>

using namespace std;

//使用if else 语句实现；把数字转换为字母成绩的要求
#if 1

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