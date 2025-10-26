#include <iostream>
#include <deque>
using namespace std;

void print_deque(const deque<int> &_d)
{
    for (deque<int>::const_iterator it = _d.begin(); it != _d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// deque 容器没有 capacity 概念，可以无限向里面添加内容
void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i + 1);
    }
    print_deque(d1);

    // 判断容器是否为空
    if (d1.empty())
    {
        cout << "d1 为空！" << endl;
    }
    else
    {
        cout << "d1 不为空！" << endl;
        cout << "d1 的大小（元素的个数）size = " << d1.size() << endl;
    }

    // 重新指定大小
    d1.resize(15); // 15 比原来大，默认用 0 来填充新的空间
    print_deque(d1);

    d1.resize(25, 1); // 比原来多出的部分用 1 来填充
    print_deque(d1);

    d1.resize(3);
    print_deque(d1);
}
int main()
{
    test01();
    return 0;
}