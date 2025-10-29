#include <iostream>
#include <algorithm>
using namespace std;

// 普通函数
void print_1(int d)
{
    cout << d << " ";
}

// 仿函数
class Print_2
{
public:
    void operator()(int d)
    {
        cout << d << " ";
    }
};

// for_each
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    // 对于遍历的每个数据，都执行 print_1() 函数
    // 通过普通函数实现遍历，需要把函数名写进去
    // for_each(v.begin(), v.end(), print_1);
    // 通过仿函数实现遍历，需要把函数对象放进去
    for_each(v.begin(), v.end(), Print_2());
}
int main()
{
    test01();
    return 0;
}

/*
    算法主要头文件：algorithm, functional, numeric
    1. algorithm: 比较、交换、查找、遍历、复制、修改
    2. numeric: 体积很小，包含在序列上进行简单数学运算的模板函数
    3. functional: 定义了一些模板类，用以声明函数对象

    一、for_each()


    二、transform()
*/