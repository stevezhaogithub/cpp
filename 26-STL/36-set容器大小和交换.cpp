#include <iostream>
#include <set>
using namespace std;

void print_set(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// 大小
void test01()
{
    // set 没有 resize() ，因为不允许有重复的数据
    set<int> s1;
    s1.insert(10);
    s1.insert(70);
    s1.insert(20);
    s1.insert(11);

    print_set(s1);

    // s1.clear();
    // 判断容器是否为空
    if (s1.empty())
    {
        cout << "s1 为空！" << endl;
    }
    else
    {
        cout << "s1 不为空！" << endl;
        cout << "s1.size() = " << s1.size() << endl;
    }
}

// 交换
void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(70);
    s1.insert(20);
    s1.insert(11);

    set<int> s2;
    s2.insert(100);
    s2.insert(700);
    s2.insert(200);
    s2.insert(110);

    cout << "交换前：" << endl;
    cout << "s1:" << endl;
    print_set(s1);
    cout << "s2:" << endl;
    print_set(s2);

    // 交换
    s1.swap(s2);
    cout << "交换后：" << endl;
    cout << "s1:" << endl;
    print_set(s1);
    cout << "s2:" << endl;
    print_set(s2);
}
int main()
{
    // test01();
    test02();
    return 0;
}