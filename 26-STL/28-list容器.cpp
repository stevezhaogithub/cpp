
/*
    list容器
    - 链式存储
    - 双向循环链表
    - 迭代器只支持前移和后移，不支持跳跃
    - 采用动态存储分配内存，不会造成内存浪费或溢出
    - 多存储指针域，遍历速度比较慢


    STL中最常使用的容器：
    - vector
    - list
*/

#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int> &_l)
{
    for (list<int>::const_iterator it = _l.begin(); it != _l.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    // 默认构造
    list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    print_list(lst);

    // 区间构造
    list<int> L2(lst.begin(), lst.end());
    print_list(L2);

    // 拷贝构造
    list<int> L3(L2);
    print_list(L3);

    // n 个 element 构造
    list<int> L4(10, 999);
    print_list(L4);
}
int main()
{
    test01();
    return 0;
}