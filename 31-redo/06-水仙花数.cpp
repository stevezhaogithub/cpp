#include <iostream>

// 打印输出所有的 3 位 "水仙花" 数
void print_armstrong_numbers()
{
    for (int i = 100; i <= 999; i++)
    {
        // 计算每一位
        int ones = i % 10;
        int tens = i / 10 % 10;
        int hundreds = i / 100;
        int total = ones * ones * ones + tens * tens * tens + hundreds * hundreds * hundreds;
        if (total == i)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}
int main()
{
    print_armstrong_numbers();
    return 0;
}