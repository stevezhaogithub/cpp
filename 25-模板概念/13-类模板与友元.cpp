#include <iostream>
#include <string>
using namespace std;

// 通过全局函数来打印 Person 的信息

// 提前让编译器知道 Person 类的存在
template <class T, class E>
class Person;

// 提前让编译器知道全局函数的存在
template <class T, class E>
void print2(Person<T, E> p)
{
    cout << "全局函数在类外部方式实现------" << "姓名：" << p.m_name << ", 年龄：" << p.m_age << endl;
}

template <class T, class E>
class Person
{

    // 全局函数, 类内实现(全局函数可以访问类的私有成员)
    friend void print(Person<T, E> p)
    {
        cout << "全局函数类内实现：-----" << "姓名：" << p.m_name << ", 年龄：" << p.m_age << endl;
    }

    // 全局函数在类外部实现(在类内部声明全局函数)
    friend void print2<>(Person<T, E> p);

public:
    Person(T _name, E _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }

private:
    T m_name;
    E m_age;
};

// // 全局函数, 类外实现
// template <class T, class E>
// void print2(Person<T, E> p)
// {
//     cout << "全局函数在类外部方式实现------" << "姓名：" << p.m_name << ", 年龄：" << p.m_age << endl;
// }

void test01()
{
    Person<string, int> p("tom", 18);
    print(p);
}

void test02()
{
    Person<string, int> p("steve", 19);
    print2(p);
}

int main()
{
    // test01();
    test02();
    return 0;
}
