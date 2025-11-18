#include <iostream>

// 全局变量在全局区
int a_global = 10;
int b_global = 10;
const int c_g_a = 10;

// 全局区: 全局变量、静态变量、常量（在 macos 下常量和局部变量在一起)
void test1()
{
    // 1. 全局区
    std::cout << "全局变量 a_global 的地址 = " << (long)&a_global << std::endl;
    std::cout << "全局变量 b_global 的地址 = " << (long)&b_global << std::endl;
    // 全局常量(全局区)
    std::cout << "全局常量 c_g_a 的地址 = " << (long)&c_g_a << std::endl;
    // 静态变量在全局区
    static int a_static = 10;
    std::cout << "静态变量 a_static 的地址 = " << (long)&a_static << std::endl;
    // 全局区
    std::cout << "字符串常量 hello wordl！的地址 = " << (long)&"hello world!" << std::endl;

    // ------------------------------------------------------------
    std::cout << "----------------------------------------------" << std::endl;
    // 2. 非全局区
    // 普通常量和普通局部变量在同一区域
    const int a_const = 10;
    std::cout << "常量 a_const 的地址 = " << (long)&a_const << std::endl;

    // 字符串常量, 与局部变量在同一区域
    std::string str = "hello";
    std::cout << "字符串常量 str 的地址 = " << (long)&str << std::endl;

    // 2. 普通局部变量
    int a = 10;
    int b = 10;
    std::cout << "局部变量 a 的地址 = " << (long)&a << std::endl;
    std::cout << "局部变量 b 的地址 = " << (long)&b << std::endl;
}

int main()
{
    test1();
    return 0;
}