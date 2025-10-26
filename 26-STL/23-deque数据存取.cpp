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
void test01()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    // 通过 [] 遍历
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;

    cout << "--------------------" << endl;
    // 通过 at 遍历
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1.at(i) << " ";
    }
    cout << endl;
    cout << "--------------------" << endl;
    cout << "第一个元素：" << d1.front() << endl;
    cout << "最后一个元素：" << d1.back() << endl;
}
int main()
{
    test01();
    return 0;
}