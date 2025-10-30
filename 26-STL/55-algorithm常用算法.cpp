#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
using namespace std;

// 仿函数
class Transform
{
public:
    int operator()(int d)
    {
        return d;
    }
};

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

// for_each 算法
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

// transform() 函数
void test02()
{
    
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i+1);
    }
    vector<int> v_target;
    // v_target 没有设置大小，所以不能向其中转移元素
    v_target.resize(v.size());                                    // 1. 先为 v_target 分配大小
    transform(v.begin(), v.end(), v_target.begin(), Transform()); // 2. 再转移数据
    for_each(v_target.begin(), v_target.end(), print_1);          // 3. 在遍历输出
}
int main()
{
    // test01();
    test02();
    return 0;
}

/*
    算法主要头文件：algorithm, functional, numeric
    1. algorithm: 比较、交换、查找、遍历、复制、修改
    2. numeric: 体积很小，包含在序列上进行简单数学运算的模板函数
    3. functional: 定义了一些模板类，用以声明函数对象

    一、for_each()


    二、transform()
    作用：搬运容器到另一个容器
*/