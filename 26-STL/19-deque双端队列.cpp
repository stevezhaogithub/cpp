#include <iostream>
#include <deque>
using namespace std;

void print_deque(const deque<int> &_d)
{
    // 注意，此处是 deque<int>::const_iterator it
    for (deque<int>::const_iterator it = _d.begin(); it != _d.end(); it++)
    {
        // 容器中的数据不可修改（因为是只读迭代器）
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // deque 双端队列，发音：deck
    // vector 对于头插效率很低；deque 头插和尾插效率都很高
    //

    // deque 构造函数
    deque<int> d1;
    for (int i = 0; i < 5; i++)
    {
        d1.push_back(i);
    }
    print_deque(d1);

    cout << "------------------" << endl;

    deque<int> d2(d1.begin(), d1.end());
    print_deque(d2);

    cout << "------------------" << endl;
    // 10 个 999
    deque<int> d3(10, 999);
    print_deque(d3);

    // 拷贝构造
    cout << "------------------" << endl;
    deque<int> d4(d3);
    print_deque(d4);
}

int main()
{

    test01();
    return 0;
}