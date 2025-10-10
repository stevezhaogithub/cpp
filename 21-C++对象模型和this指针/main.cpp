//
//  main.cpp
//  21-C++对象模型和this指针
//
//  Created by steve xiaohu zhao on 2025/10/10.
//

#include <iostream>
#include <string>
using namespace std;

// 成员变量 和 成员函数 是分开存储的
class Person {
    int m_A;
    static int m_B;
    double m_D;
    
    void func(){
        cout << "func()" << endl;
    }
};


// this 指针
class Student {
public:
    int age;
    Student(int age) {
        
        // this 表示是一个指针，指向的是被调用的成员函数所属的对象
        this->age = age;
    }
    
    Student addAge(Student &s) {
        this->age += s.age;
        return *this;
    }
    
};


void test02() {
    Student s1(18);
    s1.addAge(s1).addAge(s1).addAge(s1);
    cout << "s1 的年龄 = " << s1.age << endl;
}

void test01() {
    Person p;
    
    // 输出是 1 个字节；
    // C++ 编译器会为每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存
    cout << "size of p = " << sizeof(p) << endl;
}

int main(int argc, const char * argv[]) {
    // test01();
    test02();
    
    return 0;
}


/*/
    C++ 中成员变量和成员函数是分开存储的：
        1. 每一个分镜台成员函数，只会诞生一份函数实例，即多个同类型对象会共用一块代码。
        问题：如何区分是哪个对象调用这段函数代码呢？this
        this 指针指向被调用的成员函数所属的对象
 */
