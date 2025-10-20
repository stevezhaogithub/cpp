#include <iostream>
using namespace std;

/*
    普通函数与函数模板的调用规则：
    1、如果函数模板和普通函数都可以调用，优先调用普通函数
    2、可以通过空模板的参数列表，强制调用函数模板
    3、函数模板也可以发生函数重载
    4、如果函数模板可以产生更好地匹配，优先调用函数模板
*/

/*
    void myPrint(int a, int b)
    和
    void myPrint(T a, T b)
    可以同时存在

*/

void myPrint(int a, int b)
{
    cout << "调用的是普通函数" << endl;
}

template <class T>
void myPrint(T a, T b)
{
    cout << "调用的是函数模板" << endl;
}

// 函数模板的函数重载
template <class T>
void myPrint(T a, T b, T c)
{
    cout << "调用的是 --- 重载的 --- 函数模板" << endl;
}

void test01()
{
    int a = 10, b = 20;
    // 优先调用普通函数
    // myPrint(a, b);

    // 通过空模板的参数列表，强制调用函数模板
    // myPrint<>(a, b);

    // 调用重载的函数模板
    // myPrint(a, b, 100);

    

    // 如果函数模板产生更好的匹配，优先调用函数模板
    char ch1 = 'a', ch2 = 'b';
    // 此处会调用 函数模板
    myPrint(ch1, ch2);
}
int main()
{
    test01();
    return 0;
}