#include <iostream>
using namespace std;

class Person
{
public:
    Person(int _age)
    {
        m_age = new int(_age);
    }

    ~Person()
    {
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
    }

public:
    int *m_age;

    // 重载赋值运算符 = ，将拷贝地址变成拷贝一个副本
    Person &operator=(Person &p)
    {
        // 编译器提供的是浅拷贝(只是拷贝了指针的值)
        // m_age = p.m_age;

        // 深拷贝：先释放干净，再拷贝
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
        m_age = new int(*p.m_age);

        return *this;
    }
};

void test01()
{
    Person p1(19);
    Person p2(20);
    Person p3(99);

    // 执行赋值操作
    p3 = p2 = p1;

    cout << "p1 的年龄 = " << *p1.m_age << endl;
    cout << "p2 的年龄 = " << *p2.m_age << endl;
    cout << "p3 的年龄 = " << *p3.m_age << endl;
}

int main()
{
    test01();

    return 0;
}

/*
    C++ 默认给一个类至少添加 4 个函数
    1. 默认的无参数的构造函数
    4. 赋值运算符 operator= 重载，对属性进行值拷贝
*/