#include <iostream>
#include <string>

// 此处包含 Person.h 报错，但包含 Person.cpp 不报错
// 原因：在类模板中的成员函数在一开始是不创建的，在执行的时候才会
// #include "Person.h"
// #include "Person.cpp"

// 第二种解决方法：将 .h 和 .cpp 文件中的内容写到一起，后缀改为 .hpp
#include "Person.hpp"
using namespace std;

/*

    -----------------------------------------

    // 类模板的分文件编写
    template <class T, class E>
    class Person
    {
    public:
        // 构造函数声明
        Person(T _name, E _age);
        // 普通的类成员函数声明
        void show();
        T m_name;
        E m_age;
    };

    // 构造函数的外部实现
    template <class T, class E>
    Person<T, E>::Person(T _name, E _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }

    // 成员函数的外部实现
    template <class T, class E>
    void Person<T, E>::show()
    {
        cout << "姓名：" << this->m_name << ", 年龄：" << this->m_age << endl;
    }



    -----------------------------------------



*/

void test01()
{
    Person<string, int> jerry("杰瑞", 18);
    jerry.show();
}
int main()
{
    test01();
    return 0;
}

/*
    把 .h 和 .cpp 内容写到一起，后缀是 .hpp
*/