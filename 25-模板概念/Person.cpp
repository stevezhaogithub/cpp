#include "Person.h"
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