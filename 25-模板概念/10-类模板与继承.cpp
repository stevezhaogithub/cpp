#include <iostream>
#include <string>
using namespace std;

template <class T>
class Person
{
public:
    T m;
};

// 继承自 Person 类
// class Teacher : public Person 错误，必须知道父类中的 T 对应的具体类型，才能继承给自类
class Teacher : public Person<int>
{
};

// 继承自 Person 类
template <class T, class E>
class Student : public Person<T>
{
public:
    E m_obj;
    Student()
    {
        cout << typeid(T).name() << endl;
        cout << typeid(E).name() << endl;
    }
};

void test01()
{
    Teacher t;
}

void test02()
{
    Student<char, int> s1;
    // cout << typeid(s1).name() << endl;
}

int main()
{
    test02();
    return 0;
}