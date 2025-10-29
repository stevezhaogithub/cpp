#include <iostream>
#include <vector>
using namespace std;

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

// 仿函数
class GreaterFive
{
public:
    // 一元谓词
    bool operator()(int val)
    {
        return val > 7;
    }
};

// 仿函数
class GreaterTwenty
{
public:
    bool operator()(const Person &d)
    {
        return d.m_age > 20;
    }
};

void test02()
{
    vector<Person> v;
    Person p1("张安", 10);
    Person p2("李四", 20);
    Person p3("王五", 30);
    Person p4("赵六", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    // 查找年龄大于 20 的人
    vector<Person>::iterator it = find_if(v.begin(), v.end(), GreaterTwenty());
    if (it == v.end())
    {
        cout << "没有找到！" << endl;
    }
    else
    {
        cout << "姓名：" << it->m_name << ", 年龄：" << it->m_age << endl;
    }
}

void test01()
{
    // 1. 构建数据
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 2. find_if() 方法演练
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it != v.end())
    {
        cout << "找到了大于 5的数据了：" << endl;
        cout << *it << endl;
    }
    else
    {
        cout << "没找到！" << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}