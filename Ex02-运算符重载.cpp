#include <iostream>
#include <string>
using namespace std;

// 1. 加号运算符重载
class Person
{
public:
    int m_A;
    int m_B;

public:
    Person addPerson(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }

    // 1、通过成员函数重载 + 运算符
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }

    // 重载一个 Person 对象加 int 类型整数的+号重载运算符
    Person operator+(int num)
    {
        Person temp;
        temp.m_A = this->m_A + num;
        temp.m_B = this->m_B + num;
        return temp;
    }
};

// // 2、通过全局函数重载 + 运算符
// Person operator+(Person &p1, Person &p2)
// {
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp;
// }

void test01()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;

    Person p2;
    p2.m_A = 20;
    p2.m_B = 20;

    // Person p3 = p1 + p2;
    // 调用全局重载函数的本质
    // Person p3 = operator+(p1, p2);

    // 调用成员函数重载的本质
    Person p3 = p1.operator+(p2);

    cout << "p3 的 m_A = " << p3.m_A << "; p3 的 m_B = " << p3.m_B << endl;

    // Person p4 = p1.operator+(100);
    Person p4 = p1 + 200;
    cout << "p4.m_A = " << p4.m_A << endl;
    cout << "p4.m_B = " << p4.m_B << endl;
}

int main()
{
    test01();
    return 0;
}

// 运算符重载:
// 1. 重载运算符的本质是函数重载
