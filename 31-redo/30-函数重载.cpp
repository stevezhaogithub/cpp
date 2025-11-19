/**
 *
 *
 * 函数重载注意事项：
 * 1. 引用作为重载条件
 * 2. 函数重载碰到函数默认参数
 *
 *
 */

#include <iostream>

// 1. 引用也可以作为函数重载条件

// 带 const 的引用和不带 const 的引用可以发生重载
void fun(int &a)
{
    std::cout << "invoke fun(int &a)." << std::endl;
}
void fun(const int &a)
{
    std::cout << "invoke fun(const int &a)." << std::endl;
}

void fun(int *a)
{
    std::cout << "invoke fun(int *a)." << std::endl;
}

// 2. 函数重载遇到了带默认参数的情况
void fn(int a)
{
    std::cout << "void fn(int a)." << std::endl;
}

// 当第二个参数有默认值的时候 fn(10) 就无法判断是调用哪个函数重载了
// 建议：是使用函数重载的时候就不要写默认参数了
void fn(int a, int b = 10)
{
    std::cout << "void fn(int a, int b)" << std::endl;
}

int main()
{
    int v = 100;
    fun(v); // invoke fun(int &a).

    // 此处为什么要调用 const int &a
    // 因为:
    // int &a = 90; 不合法
    // const int &a = 90; 合法
    // 将实参赋值给形参还是一个变量赋值的过程
    fun(90); // invoke fun(const int &a).

    int a = 100;
    fun(&a);

    std::cout << "--------------------------------" << std::endl;
    fn(10);
    fn(10, 20);

    return 0;
}