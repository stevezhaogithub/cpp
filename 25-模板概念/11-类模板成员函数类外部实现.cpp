#include <iostream>
#include <string>
using namespace std;

template <class T, class E>
class Person
{
public:
    T m_name;
    E m_age;

    // // 构造函数的类内部实现
    // Person(T _name, E _age)
    // {
    //     this->m_age = _age;
    //     this->m_name = _name;
    // }

    // 类内部写构造函数的声明（类外部实现）
    Person(T _name, E _age);

    // 成员函数的类内部实现
    // void show()
    // {
    //     cout << "姓名：" << this->m_name << ", 年龄：" << this->m_age << endl;
    // }
    void show();
};

// 构造函数的类外部实现
template <class T, class E>
Person<T, E>::Person(T _name, E _age)
{
    this->m_name = _name;
    this->m_age = _age;
}

// 成员函数的类外实现
template <class T, class E>
void Person<T, E>::show()
{
    cout << "姓名：" << this->m_name << ", 年龄：" << this->m_age << endl;
}

void test01()
{
    Person<string, int> p1("张三", 18);
    p1.show();
}

int main()
{
    test01();
    return 0;
}

/*
    总结：类模板的成员函数在类外部实现的时候，需要添加“模板参数列表”—— Person<T, E>::成员名称()
*/