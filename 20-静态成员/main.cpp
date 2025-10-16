//
//  main.cpp
//  20-静态成员：成员变量 、 成员函数
//
//  Created by steve xiaohu zhao on 2025/10/10.
//

#include <iostream>
#include <string>
using namespace std;

/*
    静态成员变量:
        1. 所有对象共享同一份数据
        2. 静态成员在编译阶段分配内存（在全局区）
        3. 类内声明，类外初始化

    静态成员函数:
        1. 所有对象共享同一个函数
        2. 静态成员函数只能访问静态成员变量

 */

class Person {
  public:
    // 类内声明静态成员
    static int m_A;
    static void func() { cout << " static void func() " << endl; }

  private:
    static int m_B;
};

// 类外进行初始化
int Person::m_A = 100;
int Person::m_B = 200;

void test02() {
    // 通过对象调用静态成员函数
    Person p1;
    p1.func();
    cout << "---------------" << endl;
    // 通过类名调用静态成员函数
    Person::func();
}

void test01() {
    Person p;

    // 通过对象访问静态成员变量
    cout << p.m_A << endl;

    // 'm_B' is a private member of 'Person'
    // cout << Person::m_B << endl;

    Person p2;
    p2.m_A = 200;

    // 通过类名访问静态成员变量
    cout << Person::m_A << endl;
    
    
    test02();
}

int main(int argc, const char *argv[]) {
    test01();
    return 0;
}
