#include <iostream>
using namespace std;

class Father
{
public:
    static int m_A;
    static void func()
    {
        cout << "Father static void func() " << endl;
    }
};

int Father::m_A = 100;

class Son : public Father
{
public:
    static int m_A;
    static void func()
    {
        cout << "Son static void func() " << endl;
    }
};

int Son::m_A = 300;

// 同名的静态成员属性
void test01()
{
    cout << Father::m_A << endl;
    cout << Son::m_A << endl;

    cout << "------------------" << endl;
    Father b;
    Son s;

    cout << b.m_A << endl;
    cout << s.m_A << endl;

    cout << "==============" << endl;

    cout << Son::Father::m_A << endl;
}

// 同名的静态成员函数
void test02()
{
    // 1. 通过对象访问
    Son s1;
    s1.func();
    s1.Father::func();

    // 2. 通过类名访问
    Son::func();
    Father::func();
    Son::Father::func();
}

int main()
{
    // test01();
    test02();
    return 0;
}