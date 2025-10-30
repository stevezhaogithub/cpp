/*
    1. 求两个容器的交集, set_intersection()
    - 1） 原容器必须是有序序列
    - 2） 目标容器大小要以原容器中较小的那个为准
    - 3） set_intersection() 返回值即交集中最后一个元素的位置.
    2. 求两个容器的并集, set_union()
    3. 求两个容器的差集, set_difference()
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fn(int d)
{
    cout << d << " ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> _target;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);     // [0, 9]
        v2.push_back(i + 5); // [5, 14]
    }

    // 设置目标 vector 大小
    _target.resize(min(v1.size(), v2.size()));

    // 求交集
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), _target.begin());

    // 遍历交集结果
    for_each(_target.begin(), itEnd, fn);
    cout << endl;
}

// set_union() 并集
void test02()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> _target;

    // 初始化 v1 和 v2 中的内容
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);     // [0, 9]
        v2.push_back(i + 5); // [5, 14]
    }
    // 为目标容器开辟空间(根据 v1 和 v2的大小开辟 _target的大小)
    _target.resize(v1.size() + v2.size());

    // 求 v1 和 v2 的并集
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), _target.begin());

    // 遍历输出
    for_each(_target.begin(), itEnd, fn);
    cout << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}