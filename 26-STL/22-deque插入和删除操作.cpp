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

// 头插、尾插； 头删、尾删
void test01()
{
    deque<int> d1;

    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);

    // 头插
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    print_deque(d1); // 300 200 100 10 20 30

    // 尾删
    d1.pop_back();
    print_deque(d1);

    // 头删
    d1.pop_front();
    print_deque(d1);
}

// 指定位置插入和删除
void test02()
{
    deque<int> d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);

    // 头插
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    print_deque(d1); // 300 200 100 10 20 30

    // insert 插入（通过迭代器）
    d1.insert(d1.begin(), 9999);
    print_deque(d1);
    d1.insert(d1.begin(), 2, 100000);
    print_deque(d1);

    // 按照区间进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    print_deque(d1);
}

// 删除
void test03()
{
    deque<int> d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);

    // 根据迭代器，删除某个特定位置的元素
    d1.erase(d1.begin());
    print_deque(d1);

    // 按照区间删除
    // d1.erase(d1.begin(), d1.end());
    d1.clear();
    cout << "----" << endl;
    print_deque(d1);
    cout << "----" << endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}