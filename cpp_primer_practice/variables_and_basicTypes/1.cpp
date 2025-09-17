#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include "my.h"

using namespace std;

// test
#if 0

int main()
{
    int ia[] = {0,2,4,6,8};
    int *p = ia;
    cout << endl;
    cout << *p << endl;
    return 0;
}

#endif

#if 0

int main()
{
    cout << endl;
    //  /115 /012是八进制转义序列
    //  分别代表字符  M 和换行符
    cout << 2 << "\115\012";
    cout << 2 << "\t\115\012";

    return 0;
}

#endif

// 2.19
// 说明指针和引用的区别
// 引用是另一个对象的别名，而指针本身就是一个对象。引用必须初始化，并且一旦定义了引用就无法在绑定到其他对象。而指针无须在定义时赋初值，也可以重新赋值让其指向其他对象。

// 顶层const:约束变量本身
// 底层const:约束变量所指向的对象

#if 0

int main()
{
    int num = 19;
    string str = "hello";
    cout << endl;
    cout << typeid(str.size()).name() << endl;
    //输出y (表示usigned l)
    return 0;
}

#endif
//字符串字面值和string是不同的类型
//字符串字面值是const char数组，储存在静态存储区，内容不可修改。
//string是一个字符串类，可以动态管理字符串内容，支持丰富的操作。




#if 0

int main()
{
    vector<int> v1(4,4);
    vector<string> v2 = {"a", "an", "the"};
    v1.push_back(4);
    for(auto i : v1)//用于遍历容器中的每个元素
        cout << i << " ";
    v2.push_back("this");
    for(auto s : v2)
        cout << s << " ";
    return 0;
}

#endif

#if 0

int main()
{
    string s;
    while(getline(cin,s))//cin >> s 只能读取到空格为止，而getline可以读取整行，包括空格
    {
        cout << s << endl;
    }
    return 0;
}
#endif

// 3.4
#if 0
int main()
{
    string s1;
    string s2;
    cout << "please enter first string :";
    cin >> s1;
    cout << "please enter second string :";
    cin >> s2;
    if(s1 == s2)
    {
        cout << "the two string are equal" << endl;
    }
    else
    {
        if(s1 > s2)
            cout << s1 << " is larger than " << s2 << endl;
        else
            cout << s2 << " is larger than " << s1 << endl;
    }
    return 0;
}
#endif

// 3.6
#if 0
int main()
{
    string s = "this is a string";

    for (auto &x : s)// 使用引用以便修改字符串内容,如果不加&，x会是字符的副本，修改x不会影响s
    {
        x = 'X';
    }

    cout << s << endl;
    return 0;
}
#endif

// 3.20
#if 0
int main()
{
    vector<int> v;
    int cnt = 0;
    int vector_size = 0;
    cout << "enter some integers: ";
    while (cin >> cnt)
    {
        v.push_back(cnt);
    }
    vector_size = v.size();
    for (int i = 0; i <= vector_size / 2; i++)
    {
        cout << "第" << i + 1 << "个元素与倒数第" << i + 1 << "个元素之和为：" << v[i] + v[vector_size - i - 1] << endl;
    }
    return 0;
}
#endif

//用数组初始化Vector: int a[] = {1,2,3,4,5}; vector<int> v(begin(a), end(a));

#if 0

int main()
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // a range for to manage the iteration
    for (auto &p : ia)
        for (int q : p)
            cout << q << " ";
    cout << endl;

    // ordinary for loop using subscripts
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // using pointers.
    for (auto p = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}

#endif

//练习3.23：编写一个程序，创意一个含有10个整数的vector对象，然后使用迭代器将所有的元素的值都变成原来的两倍，输出vetor对象的内容，验证程序的正确性。

#if 0

int main()
{
    vector<int> v;
    int s;
    while (v.size() < 10 && (cin >> s))
    {
        v.push_back(s);
    }

    for(auto it = v.begin(); it != v.end(); it++)
    {
        *it = *it * 2;
    }

    for(auto i:v)
    {
        cout << i << " ";
    }

    return 0;
}
#endif

#if 1
int main()
{
    int arr[5] = {1,2,3,4,5};
    int *beg = begin(arr);
    int *last = end(arr);
    while (beg != last)
    {
        *beg = *beg * 2;
        beg++;
    }

    for(auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
#endif