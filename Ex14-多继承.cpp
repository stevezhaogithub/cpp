#include <iostream>
using namespace std;

class BaseClass1
{
public:
    BaseClass1()
    {
        m_A = 100;
        number = 999;
    }
    int m_A;

    int number;
};

class BaseClass2
{
public:
    BaseClass2()
    {
        m_B = 200;
        number = 19999;
    }
    int m_B;
    int number;
};

class SubClass : public BaseClass1, public BaseClass2
{
public:
    int m_C;
    int m_D;
    SubClass()
    {
        m_C = 300;
        m_D = 400;
    }
};

void test01()
{
    SubClass sc;
    cout << sizeof(sc) << endl;

    // 通过作用于访问不同父类的同名成员变量 number
    cout << sc.BaseClass1::number << endl;
    cout << sc.BaseClass2::number << endl;
}

int main()
{
    test01();
    return 0;
}