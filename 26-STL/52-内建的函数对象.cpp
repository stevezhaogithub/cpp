#include <iostream>
#include <functional>
using namespace std;

/*
    内建的函数对象(内建的仿函数):
    0. STL中已经写好的仿函数
    1. 导入 functional 头文件
    2. 分类：
    - 算术仿函数
        + plus<T>
        + minus<T>
        + multiplies<T>
        + divides<T>
        + modules<T> 取模
        + negate<T> 取反 - 一元运算
    - 关系仿函数
    - 逻辑仿函数
*/

void test01()
{
    negate<int> _negate;
    int ret = _negate(100);
    cout << ret << endl;
}

void test02()
{
    plus<int> _plus;
    int ret = _plus(100, 500);
    cout << ret << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}