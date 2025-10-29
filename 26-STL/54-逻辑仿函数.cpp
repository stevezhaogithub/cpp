

/*
    逻辑仿函数
    1. logical_and<T>
    2. logical_or<T>
    3. logical_not<T>

*/
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

void print_vector(const vector<bool> &v)
{
    for (vector<bool>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<bool> v;

    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    print_vector(v);

    // 利用逻辑非，将容器 v 中的内容搬运到 v1中，并执行取反操作
    vector<bool> v1;

    // 目标容器必须提前开辟空间
    v1.resize(v.size());

    //  transform() 函数，第三个参数表示在搬运的过程中要执行的操作
    transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());
    print_vector(v1);
}

int main()
{
    test01();
    return 0;
}