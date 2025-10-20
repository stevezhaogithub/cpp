#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    void showPerson()
    {
        cout << " show() in Person. " << endl;
    }
};

class Teacher
{
public:
    void showTeacher()
    {
        cout << " show() in Teacher. " << endl;
    }
};

template <class T>
class MyClass
{
public:
    T obj;
    void func1()
    {
        obj.showPerson();
    }

    void func2()
    {
        obj.showTeacher();
    }
};

void test01()
{
    MyClass<Person> mc;
    mc.func1();

    MyClass<Teacher> mc2;
    mc2.func2();
}

int main()
{
    test01();
    return 0;
}

/*
    普通类的成员函数一开始就创建了
    类模板中的成员函数，在调用时才创建
*/