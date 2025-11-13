#include <iostream>
#include <string>

// 1. 字符类型
void test1()
{
    char ch = 'A';
    std::cout << sizeof(ch) << std::endl;

    // 输出 char 对应的 ASCII 码
    std::cout << (int)ch << std::endl;

    char ch1 = 'Z';
    std::cout << (int)ch1 << std::endl;

    char ch2 = 'z';
    std::cout << (int)ch2 << std::endl;
    std::cout << "aaaaaaaaa";
    std::cout << "\v" << "aaaa" << "bbbb" << std::endl;
}

// 字符串类型
void test2()
{
    // 1. C 风格字符串
    char text[] = "hello world!!!";

    // 2. string
    std::string s1 = "Ha lou wo er de.";

    std::cout << s1 << std::endl
              << text << std::endl;

    std::cout << sizeof(bool) << std::endl;
}

int main()
{
    // test1();
    test2();
    return 0;
}

/**
 * 一、C 风格字符串
 * 
 * char str[] = "aaaa";
 *
 * 二、C++ 风格字符串
 * #include <string>
 * std::string str = "hello";
 *
 */