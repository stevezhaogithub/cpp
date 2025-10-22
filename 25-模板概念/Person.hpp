
/*
    约定俗成：.hpp 文件就是类模板
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

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