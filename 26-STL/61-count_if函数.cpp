#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// count_if()

// 仿函数
class Greater20
{
public:
    bool operator()(int d)
    {
        return d > 20;
    }
};

// 基本数据类型
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(20);
    v.push_back(50);
    v.push_back(10);

    int n = count_if(v.begin(), v.end(), Greater20());
    cout << "年龄大于 20 岁的人的个数：" << n << endl;
}

class Person
{
public:
    Person(string _name, int _age)
    {
        this->m_age = _age;
        this->m_name = _name;
    }
    string m_name;
    int m_age;
};

class AgeGreater20
{
public:
    bool operator()(Person d)
    {
        return d.m_age > 20;
    }
};

// 统计自定义数据类型
void test02()
{
    vector<Person> v;
    Person p1("steve", 18);
    Person p2("steve", 19);
    Person p3("steve", 20);
    Person p4("steve", 21);
    Person p5("steve", 22);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 统计年龄大于 20 岁的人员的个数
    int n = count_if(v.begin(), v.end(), AgeGreater20());
    cout << "年龄大于 20 岁的人的个数：" << n << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}