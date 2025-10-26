#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_vector(vector<int> &_v)
{
    for (vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back((i + 1) * 3);
    }

    // 1. 输出方式一
    // print_vector(v1);

    // // 2. 输出方式二
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     cout << v1[i] << " ";
    // }
    // cout << endl;

    // 3. 输出方式三
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    // 获取第一个元素
    cout << "v1 的第一个元素：" << v1.front() << endl;

    // 最后一个元素
    cout << "v1 的最后一个元素：" << v1.back() << endl;
}

int main()
{
    test01();
    return 0;
}
