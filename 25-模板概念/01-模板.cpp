#include <iostream>
using namespace std;

// 1. 函数模板
template <typename T> // typename 可以换成 class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 把 typename 替换成了 class
template <class T>
void doSwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 2. 类模板

// 测试方法
void test()
{
    int a = 10;
    int b = 20;

    // 使用函数模板进行数据交换
    // 两种使用模板的方法
    // 1. 自动类型推导
    // mySwap(a, b);
    // cout << "a = " << a << "; " << "b = " << b << endl;

    // 2. 显示指定类型
    // mySwap<int>(a, b);
    doSwap(a, b);
    cout << "a = " << a << "; " << "b = " << b << endl;
}

template <class T>
void func()
{
    cout << "invoke func() function." << endl;
}

int main()
{
    test();
    // 此处没有指出 T 的类型，所以无法正常调用 func() 函数
    // func();
    // 此处调用是正常的（因为无法推导出T的类型，所以必须明确指出 T 对应的类型
    func<int>();
    return 0;
}

// 模板是实现泛型编程的一种手段

/*
    函数模板使用注意事项
    1. 数据类型 T 要一致
    2. 模板必须确定出数据类型 T，然后才能使用

*/
