/**
 *
 *
 * 一、二维数组的声明方式:
 * 1. int numbers[2][3];
 * 2. int numbers[2][3] = {{1,2,3},{4,5,6}}
 * 3. int numbers[2][3] = {1,2,3,4,5,6}
 * 4. int numbers[][3] = {1,2,3,4,5,6}
 *
 *
 * 二、二维数组名的作用
 * 1. 查看数组占用空间的大小
 *
 * 2. 查看二维数组的首地址
 */

#include <iostream>
using namespace std;

void test1()
{
    // int numbers[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int numbers[2][3] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << numbers[i][j] << endl;
        }
    }
}

void test2()
{
    int nums[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    // 查看二维数组整体占用的空间
    cout << "二维数组整体占用: " << sizeof(nums) << endl; // 24
    // 查看二维数组一行的占用空间
    std::cout << "二维数组每行占空间:" << sizeof(nums[0]) << std::endl;
    std::cout << "二维数组每个元素占空间:" << sizeof(nums[0][0]) << std::endl;
    std::cout << "address: " << nums << std::endl;
    std::cout << "address: " << (long)nums << std::endl;

    // 计算二维数组的个数
    std::cout << "二维数组的行数: " << sizeof(nums) / sizeof(nums[0]) << endl;
    // 计算二维数组的列数
    int columns = (sizeof(nums[0]) / sizeof(nums[0][0]));
    std::cout << "二维数组的列数: " << columns << endl;

    // 第一行首地址
    std::cout << "第一行首地址: " << (long)nums[0] << std::endl;
    std::cout << "第一行首地址: " << (long)&nums[0] << std::endl;

    // 第二行首地址
    std::cout << "第二行首地址: " << (long)nums[1] << std::endl;
    std::cout << "第二行首地址: " << (long)&nums[1] << std::endl;

    // 第一行两个元素之间的地址差
    // 第一行首地址
    std::cout << "第一行 nums[0][0]: " << (long)&nums[0][0] << std::endl;
    std::cout << "第一行 nums[0][1]: " << (long)&nums[0][1] << std::endl;
}

int main()
{
    test2();
    return 0;
}