/**
 *
 * 一、C++ 中的关键字
 *
 * 二、C++ 标识符命名规则
 * auto
 *
 * 三、数据类型
 * short, int, long, long long
 *
 * 四、sizeof()
 *
 * 五、实型数据类型 - 浮点型
 * 1. float, 4 个字节, 有效数字范围 7 位
 * 2. double, 8 个字节, 有效数字范围 15 - 16位
 *
 * float f = 3.14; // 此处的 3.14 是 double 类型
 * float f1 = 3.14f; // 此处的 3.14 是 float 类型
 *
 */

#include <iostream>

// sizeof
// 几个常见的整数类型
void test1()
{
    short n1 = 10;
    int n2 = 10;
    long n3 = 10;
    long long n4 = 10;
    std::cout << sizeof(n1) << std::endl; // 2
    std::cout << sizeof(n2) << std::endl; // 4
    std::cout << sizeof(n3) << std::endl; // 8
    std::cout << sizeof(n4) << std::endl; // 8

    // 赋值超过 short 的上限, 则自动变成了 short 的下限了
    n1 = 32769;
    std::cout << "n1 = " << n1 << std::endl;

    std::cout << "---------------------" << std::endl;
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(long long) << std::endl;
}

// float 和 double
void test2()
{
    float f1 = 10.0f / 3.0f;
    std::cout << "f1 = " << f1 << std::endl;
    double d1 = 10.0 / 3.0;
    std::cout << "d1 = " << d1 << std::endl;
    std::cout << "================" << std::endl;
    std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
    std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
}
int main()
{

    test2();
    return 0;
}