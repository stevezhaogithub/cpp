#include <iostream>
#include <deque>
#include <algorithm> // 标准算法头文件
using namespace std;

//
void print_deque(const deque<int> &_d)
{
    for (deque<int>::const_iterator it = _d.begin(); it != _d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    print_deque(d1);

    // 默认是升序排序
    sort(d1.begin(), d1.end());
    cout << "排序后：" << endl;
    print_deque(d1);

    /*
        对于支持随机访问的迭代器容器，都可以使用 sort() 进行排序
        1. vector
        2. deque
    */
}

int main()
{
    test01();
    return 0;
}