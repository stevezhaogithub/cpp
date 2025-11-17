
/**
 * 函数分文件编写的步骤:
 * 1. 在 func.h 文件中写函数声明
 * #include <iostream>
 * using namespace std;
 * void swap(int a, int b);
 * 
 * 2. 在 .cpp 文件中写函数定义
 * #include "func.h"
 * void swap(int a, int b)
 * {
 *     int t = a;
 *     a = b;
 *     b = t;
 *     cout << "a = " << a << ", b = " << b << endl;
 * }
 * 
 * 
 * 3. 在 main.cpp 中的代码
 * #include "func.h"
 * int main()
 * {
 *     swap(10, 20);
 *     return 0;
 * }
 *
 */

#include "func.h"
int main()
{
    swap(10, 20);
    return 0;
}