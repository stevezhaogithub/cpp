#include <iostream>

int main()
{
    float f = 3e2; // 3 * 10 ^ 2 = 3 乘以 10 的 2 次方
    std::cout << f << std::endl;

    float f1 = 3e-2; // 3 乘以 10 的 负 2 次方 = 3 * 0.01 = 0.03
    std::cout << f1 << std::endl;
    return 0;
}