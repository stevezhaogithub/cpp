#include <iostream>
#include <string>
using namespace std;

void print_vector(vector<int> &_v)
{
    cout << "=";
    for (vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "=";
    cout << endl;
}

void test01()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    // 输出
    print_vector(v1);

    // 尾删
    v1.pop_back();
    print_vector(v1);

    // 插入: 提供一个迭代器进行插入
    v1.insert(v1.begin(), 199);
    print_vector(v1);

    // 在指定的位置（开始的位置），插入 2 个 9999
    v1.insert(v1.begin(), 2, 9999);
    print_vector(v1);

    // 删除: 从起始的位置，删除 1 个数据
    v1.erase(v1.begin());
    // 再删除一个
    v1.erase(v1.begin());
    print_vector(v1);

    // 删除一个区间(清空)
    v1.erase(v1.begin(), v1.end());
    print_vector(v1);
}
int main()
{
    test01();
    return 0;
}