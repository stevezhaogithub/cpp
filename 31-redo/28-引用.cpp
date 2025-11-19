/**
 *
 * 一、引用的基本使用
 * 1. 作用: 给变量起别名
 * 2. 语法: int &new_name = old_name;
 * 例如:
 * int a = 100;
 * int &b = a;
 *
 * 二、引用的注意事项
 * 1. 引用必须初始化
 * int a = 10;
 * int &b = a; // 定义的时候就必须初始化
 *
 * 2. 一旦初始化就不能改变了
 * int a = 10;
 * int &b = a;
 * int c = 20;
 * b = c; // 正确！！！这个是赋值操作，不是改别名。
 * b = &c; // 换绑
 *
 *
 * 三、 3 种参数传递
 * 1. 值传递
 * 2. 地址传递
 * 3. 引用传递
 *
 * 四、引用做函数的返回值
 * 1. 不要返回局部变量的引用
 *
 * 2. 函数的调用可以作为左值
 *
 *
 *
 *
 */

#include <iostream>

void test01()
{
    int a = 10;
    int &b = a;

    std::cout << b << std::endl;
    int c = 20;

    // 这里只是赋值，不是改别名
    b = c;
    // &b = c; // 错误，不能改绑定
    std::cout << a << std::endl;
}

void test02()
{
    int a = 10;
    int *b = &a;
    std::cout << *b << std::endl;
}

// 值传递
void swap1(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

// 地址传递
void swap2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// 引用传递
void swap3(int &x, int &y)
{
    // 形参 x 就是 实参的别名
    // 形参 y 就是 实参的别名
    int t = x;
    x = y;
    y = t;
}

void test03()
{
    // 1. 值传递
    int a = 10, b = 20;
    swap1(a, b);
    std::cout << a << ", " << b << std::endl;

    // 2. 地址传递
    // swap2(&a, &b);
    // std::cout << a << ", " << b << std::endl;

    // 3. 引用传递
    swap3(a, b);
    std::cout << a << ", " << b << std::endl;
}

// 返回了局部变量的引用
int &test04()
{
    int a = 10;
    //  warning: reference to stack memory associated with local variable 'a' returned [-Wreturn-stack-address]
    return a;
}

// 函数调用作为左值
// 返回值类型是 int &, 表示返回的是一个真实变量的 "别名"。这个真实的变量就是 a
int &test05()
{
    static int a = 10;
    return a;
}

int main()
{
    // test01();
    // test02();
    // test03();

    // ---------------------------------------------------

    // // 返回局部变量的引用
    // int &ret = test04();
    // std::cout << ret << std::endl;
    // std::cout << ret << std::endl; // 输出结果不正常了

    // --------------------------------------------------
    int &ret = test05();
    std::cout << ret << std::endl;
    std::cout << ret << std::endl;

    // 函数调用作为左值
    test05() = 1000;
    std::cout << ret << std::endl;
    std::cout << ret << std::endl;

    return 0;
}