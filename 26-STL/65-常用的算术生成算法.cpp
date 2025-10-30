/*
    1. accumulate(), 计算容器元素累计总和
    2. fill(), 向容器中添加元素
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// accumulate()算法
void test01()
{
    vector<int> v;
    for (int i = 1; i <= 100; i++)
    {
        v.push_back(i);
    }
    // 计算总和,第三个参数表示起始的累加值
    // accumulate()算法的头文件是：numeric
    int total = accumulate(v.begin(), v.end(), 0);
    cout << "sum = " << total << endl;
}

void fn(int d)
{
    cout << d << " ";
}

// fill() 算法, #include <numeric>
void test02()
{
    vector<int> v;
    v.resize(10);

    // 重新填充
    fill(v.begin(), v.end(), 1001);
    for_each(v.begin(), v.end(), fn);
    cout << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}