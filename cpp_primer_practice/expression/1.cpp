#include <bits/stdc++.h>

using namespace std;

//test
#if 0

int main()
{
    int a = 1,b = 2;
    int c = (a++, b++); // a 先自增，b 再自增，c 的值为 b++ 后的值（即 3）
    cout << "a: " << a << ", b: " << b << ", c: " << c;
    cout << endl;
    return 0;
}

#endif

//逻辑与运算符和逻辑或运算符都是先求左侧运算对象的值再求右侧运算对象的值，当且仅当左侧运算对象无法确定表达式的结果时才会计算右侧运算对象的值。这种策略称为“短路求值”。

#if 0

int main()
{
    int i;
    //是赋值表达式，把42赋值给变量i,然后判断i是否为真。结果是ture，因为i被赋值为42
    if(i = 42);
    //是比较表达式，判断i是否等于42.如果相等则为ture,否则为false
    if(i == 42);
    //~'q' << 6
    //在表达式 ~'q' << 6 的计算过程中，char 类型会提升为 int 类型。
    //c++中，算术运算符在操作char类型时，会自动将其提升为int，以保证运算的正确性和避免溢出。这是因为c++的整形提升规则，所有小于int的整形（如char、short）在表达式中会先转换为int在参与运算。
}

#endif 

#if 1

int main()
{
	cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;

	cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
	cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
	cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
	cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl << endl;

	cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
	cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
	cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
	cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;

	cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
	cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
	cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;

	return 0;
}
#endif

#if 0

int main()
{
    char cval;
    int ival;
    unsigned int ui;
    float fval;
    double dval;
    //ival 转换为 double，ui 转换为 double，结果转换为 float
    fval = ui - ival * 1.0;
    //c++运算符会自动进行类型提升，优先保证参与运算的类型一致，遵循“整形提升”和“浮点提升”规则。遇到不同类型时，优先提升为2更高精度的类型（比如double）.
    //赋值时会进行类型转换以匹配左侧变量类型

    return 0;
}
#endif 
