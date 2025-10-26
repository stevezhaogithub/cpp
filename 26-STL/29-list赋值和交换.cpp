#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int> &_list)
{
    for (list<int>::const_iterator it = _list.begin(); it != _list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 赋值操作
void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    print_list(L1);

    list<int> L2;
    L2 = L1;
    print_list(L2);

    list<int> L3;
    L3.assign(L1.begin(), L1.end());
    print_list(L3);

    list<int> L4;
    L4.assign(10, 9999);
    print_list(L4);
}

// 交换操作
void test02()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    list<int> L2;
    L2.assign(10, 1000);

    cout << "交换前：" << endl;
    print_list(L1);
    print_list(L2);

    L1.swap(L2);
    cout << "交换后：" << endl;
    print_list(L1);
    print_list(L2);
}
int main()
{
    // test01();
    test02();
    return 0;
}