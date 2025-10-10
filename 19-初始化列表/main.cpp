#include <iostream>
#include <string>
using namespace std;

// 初始化列表
class Person {
  public:
    int m_a;
    int m_b;
    int m_c;
    // 传统通过 构造函数初始化
    //    Person(int a, int b, int c) {
    //        m_a = a;
    //        m_b = b;
    //        m_c = c;
    //    }

    // 通过初始化列表初始化属性
    // 1.
    // Person() : m_a(100), m_b(200), m_c(300) {}
    // 2.
    Person(int a, int b, int c) : m_a(a), m_b(b), m_c(c) {}

    void show() {
        cout << "a = " << m_a << ", b = " << m_b << ", c = " << m_c << endl;
    }
};

//// 思考A和B的构造函数和析构函数执行顺序
// class A {
//
// };
//
// class B {
//     A a;
// }

class Phone {
  public:
    // 手机品牌
    string m_brand;
    Phone(string brand) {
        m_brand = brand;
        cout << "Phone 的构造函数被执行了！" << endl;
    }

    ~Phone() { cout << "Phone 的析构函数" << endl; }
};

class Student {
  public:
    Student(string name, string brand) : m_name(name), m_phone(brand) {
        cout << "Student 的构造函数被执行了！" << endl;
    }
    string m_name;
    Phone m_phone;

    void show() {
        cout << "姓名：" << m_name << " - 手机品牌：" << m_phone.m_brand
             << endl;
    }

    ~Student() { cout << "Student 的析构函数 " << endl; }
};

int main() {
    // 1、通过传统调用构造函数初始化属性
    Person p(10, 20, 30);

    //    // 2、通过初始化列表初始化属性
    //    Person p;

    // 3、类作为对象的成员
    Student s1("steve", "iPhone");
    cout << "---------------------" << endl;
    s1.show();
    p.show();
    return 0;
}

// 1、构造函数执行顺序：1. 先执行所包含的对象的构造函数，再执行自己的构造函数
// 2、析构函数执行顺序：1. 先执行对象自己的析构函数，再执行所包含的对象的析构函数
