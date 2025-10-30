#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 统计元素出现的次数(内置数据类型)
void test01()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(20);
    v1.push_back(40);
    // 找 40 出现的次数
    int num = count(v1.begin(), v1.end(), 40);
    cout << num << endl;
}
class Person
{
public:
    Person(string _name, int _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }
    bool operator==(const Person &p)
    {
        return this->m_age == p.m_age;
    }
    string m_name;
    int m_age;
};

void test02()
{
    // 统计元素出现的次数(内置数据类型)
    vector<Person> v;
    Person p1("刘备", 30);
    Person p2("关羽", 30);
    Person p3("张飞", 30);
    Person p4("赵云", 35);
    Person p5("黄忠", 40);
    Person p6("马超", 50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);

    Person p_demo("诸葛亮", 30);

    // 统计
    int n = count(v.begin(), v.end(), p_demo);

    cout << "与诸葛亮同岁数的人个数为：" << n << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}