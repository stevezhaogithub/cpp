/*
    1. accumulate(), 计算容器元素累计总和
    2. fill(), 向容器中添加元素
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

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
int main()
{
    test01();
    return 0;
}