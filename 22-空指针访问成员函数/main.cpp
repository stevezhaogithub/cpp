//
//  main.cpp
//  22-空指针访问成员函数
//
//  Created by steve xiaohu zhao on 2025/10/10.
//

#include <iostream>
using namespace std;

class Person {
  public:
    void showClassName() { cout << "this is Person class " << endl; }
    void showAge() { cout << "age = " << m_age << endl; }

    int m_age;

    // 加 mutable 关键字后，即便在 const 函数中也可以修改该成员变量的值
    mutable int m_B;
};

void test01() {
    Person *p = NULL;

    // 异常
    //    p->showAge();

    // 不异常
    p->showClassName();
}

int main(int argc, const char *argv[]) {
    // insert code here...
    test01();
    return 0;
}

/*
    空指针是可以访问成员函数的：
    1、对于函数中没有通过this访问成员变量的，不会报异常
    2、对于函数中有通过this访问成员变量的，会报异常
 */

/*
    一、常函数
    1. 成员函数后加 const 关键字
    2. 常函数内不可以修改成员属性
    3. 成员属性声明时，加关键字 mutable，在常函数中依然可以修改


    二、常对象
    1. 常对象只能调用常函数
    2. 声明对象前加 const 关键字，则该对象为常对象


 */

class Chinese {
  public:
    // 常函数
    // this 指针的本质：是指针常量（指针的指向不能修改）
    // Chinese * const this;
    // 在函数后面再加 const 关键字相当于：
    // const Chinese * const this
    // 即不仅指针的指向不可以修改，指针指向的内容也不可以修改
    void show() const {
        // 报错，this 指针不能指向其他地方
        //        this = NULL;
        this->m_B = 200;
    }
    
    Chinese() {
        
    }

    int m_age;

    mutable int m_B;
};

void test02() {
    
    // 常对象：在对象前加 const 关键字，变为常对象
    const Chinese cn;
}
