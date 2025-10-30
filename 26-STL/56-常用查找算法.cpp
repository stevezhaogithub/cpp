/*
    常用查找算法
    1. find(), 查找元素并且返回迭代器
    2. find_if()
    3. adjacent_find()
    4. binary_search()
    5. count
    6. count_if

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Person
{
public:
    Person(string _name, int _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }

    // 重载 ==
    bool operator==(const Person &p)
    {
        return ((this->m_name == p.m_name) && (this->m_age == p.m_age));
    }
    string m_name;
    int m_age;
};

// 查找自定义数据类型
void test01()
{

    cout << "----------------- int 类型比较 --------------------" << endl;
    // 1. 查找 int 类型
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // find
    vector<int>::iterator it = find(v.begin(), v.end(), 5000);
    if (it == v.end())
    {
        cout << "没有找到！" << endl;
    }
    else
    {
        cout << "找到了：" << *it << endl;
    }

    cout << "----------------- 自定义类型比较 --------------------" << endl;
    // 2. 查找自定义 Person 类型
    vector<Person> v1;
    Person p1("史蒂夫", 19);
    Person p2("鲍勃", 29);
    Person p3("杰斐逊", 190);
    Person p4("乔治", 9);
    Person p5("华盛顿", 19);

    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);

    // // find(), 需要重载 Person 类中的 ==, 否则不知道如何对 Person 对象进行比较
    vector<Person>::iterator it_p = find(v1.begin(), v1.end(), p3);
    if (it_p != v1.end())
    {
        cout << "找到了！" << endl;
        cout << it_p->m_name << ", " << it_p->m_age << endl;
    }
    else
    {
        cout << "未找到！" << endl;
    }
}

int main()
{
    test01();
    return 0;
}