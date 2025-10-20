#include <iostream>
using namespace std;

// 1. 函数模板
template <typename T>
void mySwap(T &a, T &b)
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
    mySwap<int>(a, b);
    cout << "a = " << a << "; " << "b = " << b << endl;
}
int main()
{
    test();
    return 0;
}

// 模板是实现泛型编程的一种手段
