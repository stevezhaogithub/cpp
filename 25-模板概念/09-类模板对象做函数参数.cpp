#include <iostream>
#include <string>
using namespace std;

template <class T, class E>
class Person
{
public:
    T name;
    E age;
    Person(T _name, E _age)
    {
        this->name = _name;
        this->age = _age;
    }
    void show()
    {
        cout << "姓名：" << this->name << endl;
        cout << "年龄：" << this->age << endl;
    }
};

// 1、指定传入类型（最常用）
void printing(Person<string, int> &p)
{
    p.show();
}

void test01()
{
    Person<string, int> p1("steve", 18);
    printing(p1);
}

// 2、参数模板化
template <class T1, class T2>
void print2(Person<T1, T2> &p)
{
    p.show();

    // 查看 T1 和 T2 的数据类型
    cout << "T1 的数据类型：" << typeid(T1).name() << endl;
    cout << "T2 的数据类型：" << typeid(T2).name() << endl;
}

void test02()
{
    Person<string, int> p1("steve", 18);
    print2(p1);
}

// 3、整个类模板化
template <class T>
void print3(T &p)
{
    p.show();

    // 查看 p 的数据类型
    string str = typeid(T).name();
    cout << str << endl;
}

void test03()
{
    Person<string, int> p3("孙悟空", 1000);
    print3(p3);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}

/*
    类模板对象做函数参数
    1、指定传入类型

    2、参数模板化

    3、整个类模板化


*/