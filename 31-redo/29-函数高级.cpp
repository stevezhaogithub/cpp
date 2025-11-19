/**
 *
 * 一、函数的默认参数
 * 1. 如果传入参数则使用传入的参数，如果没有传入参数则使用默认值
 * 2. 如果在定义形参的时候，某个位置出现了默认值，则从此位置开始，后面的参数都必须有默认值
 * 3. 如果函数的声明有了默认参数，则函数的实现就不能有默认参数
 * - 声明和实现只能有一个地方有默认参数
 *
 * // 函数声明
 * int add_func(int a = 10, int b = 10);
 *
 * // 函数实现(下面的函数不能再写默认参数了)
 * int add_func(int a, int b)
 * {
 *     return a + b;
 * }
 *
 * 二、
 *
 *
 *
 */

#include <iostream>

void test_func(int a = 10, int b = 200)
{
    std::cout << "a = " << a << ", b = " << b << std::endl;
}

int add(int a = 10, int b = 20, int c = 30)
{
    return a + b + c;
}

// 函数声明
int add_func(int a = 10, int b = 10);

// 函数实现
int add_func(int a, int b)
{
    return a + b;
}

int main()
{
    // test_func(1, 2);
    // test_func();
    // int ret = add();
    int ret = add(1, 2);
    std::cout << ret << std::endl;
    return 0;
}