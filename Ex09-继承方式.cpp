
#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son1 : public Base1
{

public:
    void func1()
    {
        // 父类中的 public 成员，在子类中依然是 public
        m_A = 200;
        cout << "m_A = " << m_A << endl;

        // 父类中的 protected 成员，子类中依然是 protected
        m_B = 300;
        cout << "m_B = " << m_B << endl;

        // 父类中的 private 成员，子类中访问不到
        // m_C;
    }
};

class Base2
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son2 : protected Base2
{
public:
    void func()
    {
        // m_C; 父类中的私有成员，在子类中依然无法访问
        // m_A; 父类中的 public 成员到子类中成了 protected 成员

        cout << m_A << " - - - " << m_B << endl;
    }
};

void test02()
{
    Son2 s2;
    // cout << s2.m_A << endl;
    // s1.m_A 和 m_B 都是 protected 在类外部都无法访问
}

void test01()
{
    Son1 s1;
    s1.func1();
    // cout << "m_A = " << s1.m_A << endl;

    // Son1 继承过来后，m_B 变成了 protected，在类外部无法访问了
    // s1.m_B;
}

class Base3
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son3 : private Base3
{
    public:
    void func()
    {
        // m_A 和 m_B 在 Son3中都成为 private 成员了
        cout << m_A << endl;
        cout << m_B << endl;
        // 父类中的 private 成员，子类访问不到
        // cout << m_C << endl;
    }
};

int main()
{
    test01();
    return 0;
}

// 继承的方式：
/*
    1. 公共继承
    2. 保护继承
    3. 私有继承


*/