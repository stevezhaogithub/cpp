#include <iostream>

// 定义一个宏常量
#define __SIZE__ 100
#define DAY 7

int main()
{
    std::cout << "一周共 " << DAY << "天。" << std::endl;
    const int N = 20;
    std::cout << "N的值是 " << N << std::endl;

    // DAY = 100; // expression is not assignable
    // N = 90;    // cannot assign to variable 'N' with const-qualified type 'const int'

    return 0;
}

/**
 * 定义常量两种方法:
 * 1. #define 宏常量
 * 2. const 关键字
 *
 *
 *
 *
 */