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
