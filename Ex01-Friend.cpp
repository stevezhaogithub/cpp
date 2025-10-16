#include <iostream>
#include <string>
using namespace std;

class House;

class Person
{
public:
    Person();
    void visit();
    void visit2();
    House *house;
};

class House
{
    // 一、
    // 让 Person 类中的 visit2 可以访问 House 类的私有成员（方式一）
    // 将 Person 类设置为 House 类的友元类
    // friend class Person;


    // 二、
    // 让 Person 类中的 visit2 可以访问 House 类的私有成员（方式二）
    // 将 Person 类中的 visit2 函数设置为 House 类的友元函数
    friend void Person::visit2();
    friend void Person:: visit();

public:
    House();

public:
    string m_livingRoom;

private:
    string m_bedRoom;
};

// 在类外实现成员函数
House::House()
{
    m_livingRoom = "living room";
    m_bedRoom = "bed room";
}

Person::Person()
{
    house = new House;
}

void Person::visit()
{
    cout << "visit 函数访问：" << house->m_livingRoom << endl;
    cout << "visit2 函数访问：" << house->m_bedRoom << endl;
}

void Person::visit2()
{
    // 非友元的情况下，无法访问类的私有成员
    //  cout << "visit2 函数访问：" << house->m_bedRoom << endl; // 报错
    cout << "visit2 函数访问：" << house->m_bedRoom << endl;
}

void test01()
{
    Person pp;
    pp.visit();
    pp.visit2();
}

int main()
{
    test01();
    return 0;
}