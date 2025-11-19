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
 * 二、函数占位参数
 * 1. 在函数的声明或定义中写出参数类型但不写参数名，用来占位（表示有这个参数类型），
 * 但函数体里不使用该参数。
 *
 * 2. 占位参数也可以有默认值
 *
 *
 * 用途/优点：
 * 1. 在头文件中只表明类型，避免暴露实现细节（或者当名称无意义时）。
 * 2. 明确告诉读者：这个参数存在但实现内不需要时可以省略名字。
 *
 * 注意：
 * 1. 如果在定义中省略参数名，就 无法 在函数体中使用该参数。
 * 2. 省略名字不会影响函数签名、重载或调用。
 *
 *
 *
 */

#include <iostream>

// 默认参数1
void test_func(int a = 10, int b = 200)
{
    std::cout << "a = " << a << ", b = " << b << std::endl;
}

int add(int a = 10, int b = 20, int c = 30)
{
    return a + b + c;
}

// 默认参数2

// 函数声明
int add_func(int a = 10, int b = 10);

// 函数实现
int add_func(int a, int b)
{
    return a + b;
}

// 函数占位参数: 第二个参数就是占位用的
void func1(int a, int)
{
    std::cout << "function call." << std::endl;
}

void func2(int a, int = 100)
{
    std::cout << a << std::endl;
}
int main()
{
    // test_func(1, 2);
    // test_func();
    // int ret = add();
    // int ret = add(1, 2);
    // std::cout << ret << std::endl;

    // 2函数占位参数
    // func1(100, 10);
    func2(100, 200);
    return 0;
}