#include <iostream>
#include <set>
using namespace std;

class Person
{
public:
    Person(string _name, int _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }
    string m_name;
    int m_age;
};

class Compare_Person
{
public:
    // 仿函数
    bool operator()(const Person &p1, const Person &p2) const
    {
        // 按照年龄降序排序
        return p1.m_age > p2.m_age;
    }
};

void test01()
{
    set<Person, Compare_Person> s;
    Person p1("刘备", 24);
    Person p2("关羽", 28);
    Person p3("张飞", 25);
    Person p4("赵云", 21);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    // 遍历输出
    for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << it->m_name << ", 年龄：" << it->m_age << endl;
    }
}

int main()
{
    test01();
    return 0;
}