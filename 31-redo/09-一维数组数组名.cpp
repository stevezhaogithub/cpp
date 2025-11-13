#include <iostream>

int main()
{
    // 1. 统计数组长度
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    std::cout << sizeof(nums) << std::endl;               // 28
    std::cout << sizeof(nums) / sizeof(int) << std::endl; // 7

    // 2. 获取数组在内存中的首地址
    std::cout << "数组首地址: " << nums << std::endl;
    // 将地址转换为十进制
    std::cout << "数组首地址: " << (long)nums << std::endl;

    // 数组中第一个元素的首地址
    std::cout << "数组中第 1 个元素的首地址: " << &nums[0] << std::endl;
    std::cout << "数组中第 1 个元素的首地址: " << (long)&nums[0] << std::endl;

    // 地址越来越大
    std::cout << "数组中第 2 个元素的首地址: " << (long)&nums[1] << std::endl;

    return 0;
}

/**
 *
 * 一、一维数组数组名的用途:
 * 1. 统计整个数组在内存中的长度
 * 2. 可以获取数组在内存中的首地址
 *
 *
 *
 * 二、特别注意:
 * 数组名是常量, 不能赋值. 不能为数组名赋值！！！！！！！
 */