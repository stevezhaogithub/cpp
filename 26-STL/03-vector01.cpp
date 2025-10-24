#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
    vector 容器存放自定义数据类型
*/

class Person
{
public:
    string m_name;
    int m_age;
    Person(string _name, int _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }
};

void print_fn(Person _data)
{
    cout << "for_each: 姓名：" << _data.m_name << ", 年龄：" << _data.m_age << endl;
}

void test01()
{
    vector<Person> v;

    Person p1("张三", 18);
    Person p2("李四", 19);
    Person p3("王五", 20);
    Person p4("赵六", 21);
    Person p5("田七", 22);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // // 遍历1：
    // vector<Person>::iterator it_begin = v.begin();
    // vector<Person>::iterator it_end = v.end();
    // while (it_begin != it_end)
    // {
    //     cout << "姓名：" << it_begin->m_name << ", 年龄：" << it_begin->m_age << endl;
    //     it_begin++;
    // }

    // // 遍历2：
    // for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
    // {
    //     cout << "for - loop: 姓名：" << it->m_name << ", 年龄：" << it->m_age << endl;
    // }

    // 遍历3
    for_each(v.begin(), v.end(), print_fn);
}

// 存储指针
void test02()
{
    vector<Person *> v;
    Person p1("张三", 18);
    Person p2("李四", 19);
    Person p3("王五", 20);
    Person p4("赵六", 21);
    Person p5("田七", 22);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 遍历
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Name：" << (*it)->m_name << ", Age：" << (*it)->m_age << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}