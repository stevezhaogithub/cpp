#include <iostream>
#include <deque>
using namespace std;

void print_deque(deque<int> &_d)
{
    for (deque<int>::const_iterator it = _d.begin(); it != _d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// deque 容器的赋值操作
void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    print_deque(d1);

    // 通过 operator= 赋值
    deque<int> d2;
    d2 = d1;
    print_deque(d2);

    // 通过 assign() 赋值
    deque<int> d3;
    // 通过 Iterator 枚举器进行区间赋值
    d3.assign(d1.begin(), d1.end());
    print_deque(d3);

    // 通过 n 个值赋值
    deque<int> d4;
    d4.assign(10, 999);
    print_deque(d4);
}

int main()
{

    test01();
    return 0;
}