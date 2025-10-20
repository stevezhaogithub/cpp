#include <iostream>
#include <string>
using namespace std;

/*
    一些特定的数据类型，需要一些具体化的是实现方式
    1、比较两个数据是否相等
*/

template <class T>
bool is_equal_fn(T &a, T &b)
{
    return a == b;
}

class Person
{
public:
    string m_name;
    int m_age;
    Person(string _name, int _age)
    {
        this->m_age = _age;
        this->m_name = _name;
    }
};


// 具体化的模板：具体化的一个函数模板（针对特定数据类型 Person）
template <>
bool is_equal_fn(Person &p1, Person &p2)
{
    if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    int a = 10, b = 20;
    bool ret = is_equal_fn(a, b);
    cout << ret << endl;
}

void test02()
{
    Person p1("tom", 10);
    Person p2("tom", 100);
    bool ret = is_equal_fn(p1, p2);
    if (ret)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }
}
int main()
{
    // test01();
    test02();
    return 0;
}