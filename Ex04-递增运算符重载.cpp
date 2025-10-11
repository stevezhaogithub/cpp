#include <iostream>
using namespace std;

class MyInteger
{

    // friend
    friend ostream &operator<<(ostream &cout, MyInteger n);

public:
    MyInteger()
    {
        m_number = 10;
    }

    // 重载前置一元运算符 ++
    MyInteger &operator++()
    {
        m_number++;
        return *this;
    }

    // 重载后置 ++ 运算符
    // 注意：后置递增返回的是值，而不是引用。因为后置递增中 temp 是局部变量，如果只直接返回 temp 则局部变量已经被销毁了。
    MyInteger operator++(int)
    {
        // 1. 记录当时的结果
        MyInteger temp = *this;

        // 2. 递增
        m_number++;
        // 3. 返回当时记录的结果
        return temp;
    }

private:
    int m_number;
};

// 通过全局函数，重载 << 运算符
// 此处之所以要返回 ostream & 而不是 ostream，是因为 多次 ++ 后，原来的对象的值要变，否则每次复制一个++，原来的值不变
ostream &operator<<(ostream &cout, MyInteger n)
{

    cout << n.m_number << endl;
    return cout;
}


// 测试前置 ++
void test01()
{
    MyInteger n;
    cout << ++(++(++n)) << endl;

    cout << "n = " << n;
}

// 测试后置 ++
void test02()
{
    MyInteger N;
    cout << N++ << endl;
    cout << N << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}