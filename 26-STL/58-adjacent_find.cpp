/*
    adjacent_find()
    1. 查找相邻重复元素
    2. 会返回第一个位置的迭代器
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void test01()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(3); // 相邻重复元素
    v.push_back(1);
    v.push_back(4);
    v.push_back(0);
    v.push_back(3);
    v.push_back(0);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
    {
        cout << "未找到！！" << endl;
    }
    else
    {
        cout << "找到相邻重复元素！！" << endl;
        cout << *it << endl;
    }
}

int main()
{
    test01();
    return 0;
}