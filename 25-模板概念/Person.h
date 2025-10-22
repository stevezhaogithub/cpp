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