#include <iostream>
#include <list>
#include <string>
using namespace std;

class Person
{
public:
    Person(string _name, int _age, int _height)
    {
        this->m_name = _name;
        this->m_age = _age;
        this->m_height = _height;
    }
    string m_name;
    int m_age;
    int m_height;
};

// 排序规则函数
bool compare_person(Person &p1, Person &p2)
{
    if (p1.m_age == p2.m_age)
    {
        // 年龄如果相同，则按照身高排序
        return p1.m_height < p2.m_height;
    }
    else
    {
        // 按照年龄升序排序
        return p1.m_age < p2.m_age;
    }
}

void test01()
{
    // 创建容器
    list<Person> L;
    // 添加数据
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 55, 185);
    Person p4("赵云", 65, 195);
    Person p5("张飞", 35, 275);
    Person p6("关羽", 35, 199);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    // 输出
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名：" << it->m_name << ", 年龄：" << it->m_age << ", 身高：" << it->m_height << endl;
    }
    cout << "----------------------" << endl;
    // 排序
    cout << "排序后：" << endl;

    // 必须指定排序规则
    L.sort(compare_person);
    // 输出
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名：" << it->m_name << ", 年龄：" << it->m_age << ", 身高：" << it->m_height << endl;
    }
}

int main()
{
    test01();
    return 0;
}