#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "func in Base class " << endl;
    }

    void func(int a)
    {
        cout << "func(int a) in Base class" << endl;
    }
    int m_A;
};

class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    int m_A;

    // 子类中的 func() 会隐藏所有父类中的同名的函数（包含父类中的该名称的所欲函数重载）
    void func()
    {
        cout << "func in Son class " << endl;
    }
};

// 同名的成员属性的处理方式
void test01()
{
    Son s1;
    cout << s1.m_A << endl;
    cout << s1.Base::m_A << endl;
}

// 同名的成员函数的处理方式
void test02()
{
    // 调用 Son 对象的 func() 方法
    Son s1;

    // 调用子类中的 func()
    s1.func();
    // 调用父类中的 func()
    s1.Base::func();

    s1.Base::func(100);
}

int main()
{
    // test01();
    test02();
    return 0;
}