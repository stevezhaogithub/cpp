#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

class MyCompare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void print_vector(vector<int> &v)
{
    // 遍历
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 内建函数对象 - 关系仿函数

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(70);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);

    // 遍历
    print_vector(v);

    // 默认排序（升序排序）
    sort(v.begin(), v.end());
    print_vector(v);

    // 降序排序
    // 自定义仿函数实现降序排序
    // sort(v.begin(), v.end(), MyCompare());
    // 使用内置仿函数 greater 实现降序排序
    sort(v.begin(), v.end(), greater<int>());

    print_vector(v);
}

int main()
{
    test01();
    return 0;
}

/*
    关系仿函数:
    1. equal_to<T>
    2. not_equal_to<T>
    3. greater<T>
    4. greater_equal<T>
    5. less<T>
    6. less_equal<T>

*/