#include <iostream>
using namespace std;

/*
    普通函数 与 函数模板的区别：
    1、普通函数调用的时候可以发生隐式类型转化
    2、函数模板用自动类型推导，不可以发生隐式类型转换
    3、函数模板：用显示指定类型，可以发生隐式类型转换
*/

// 普通函数
int add01(int a, int b)
{
    return a + b;
}

void test01()
{
    int a = 10, b = 20;
    cout << add01(a, b) << endl;
    cout << "---------------------" << endl;
    int c = 'a';
    // 1、普通函数调用的时候可以发生隐式类型转化
    // char 类型 'a' 隐式转换成了 int 类型
    cout << add01(a, c) << endl;
}

template <class T>
T add02(T a, T b)
{
    return a + b;
}

void test02()
{
    int a = 10, b = 20;
    char c = 'a';
    // ok
    // cout << add02(a, b) << endl;

    // not ok
    // 2、函数模板用自动类型推导，不可以发生隐式类型转换
    // 根据参数 a 推断 T 是 int 类型；根据 c 推断 T 是 char 类型，推断冲突，所以不 OK
    // cout << add02(a, c) << endl;

    // ok
    // 3、函数模板：用显示指定类型，可以发生隐式类型转换
    cout << add02<int>(a, c) << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}
