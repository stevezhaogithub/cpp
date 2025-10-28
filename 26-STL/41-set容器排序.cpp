#include <iostream>
#include <set>
using namespace std;

class MyCompare
{
public:
    // 仿函数
    bool operator()(int a, int b) const
    {
        return a > b; // 降序排序
    }
};

// set 容器排序
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(11);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 指定排序规则为从大到小（在插入数据之前就改变排序规则）
    set<int, MyCompare> s2;

    s2.insert(10);
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);
    s2.insert(50);

    for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    return 0; 
}

/*

    技术支持工程师


    远程技术支持工程师 base 西安，类似于客服，帮客户处理问题

*/
