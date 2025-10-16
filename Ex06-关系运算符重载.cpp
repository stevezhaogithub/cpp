#include <iostream>
#include <string>
using namespace std;

// 关系运算符重载
class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

    // 重载 == 关系运算符
    bool operator==(Person &p)
    {
        if (m_name == p.m_name && m_age == p.m_age)
        {
            return true;
        }

        return false;
    }

    // 重载 != 关系运算符
    bool operator!=(Person &p)
    {
        if (this->m_age != p.m_age || this->m_name != p.m_name)
        {
            return true;
        }
        return false;
    }

    string m_name;
    int m_age;
};

void test01()
{
    Person p1("tom", 18);
    Person p2("jerry", 18);
    if (p1 == p2)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }
}

void test02()
{
    Person p1("tom", 18);
    Person p2("tom", 18);
    if (p1 != p2)
    {
        cout << "p1 != p2" << endl;
    }
    else
    {
        cout << "p1 == p2" << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}