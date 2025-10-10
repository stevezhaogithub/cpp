//
//  main.cpp
//  15-对象初始化和清理
//
//  Created by steve xiaohu zhao on 2025/10/9.
//

#include <iostream>
using namespace std;

// 构造函数 和 析构函数

class Person {
  public:
    Person() {
        // 构造函数
        cout << "Person 的构造函数被执行了！" << endl;
    }

    Person(int age) { cout << "带整数参数的构造函数被执行了" << endl; }

    // 拷贝构造函数
    Person(const Person &p) { cout << "拷贝构造函数被执行了！" << endl; }

    // 析构函数
    ~Person() { cout << "析构函数被执行！！" << endl; }
};

void test01() { Person p1; }

int main(int argc, const char *argv[]) {
    // insert code here...
    // test01();

    // 调用构造函数的几种方式
    // 1、括号法
    // 调用无参构造函数的时候，不需要写（）；Person p1(); 会认为是函数声明
    Person p1;     // 默认调用无参数的构造函数
    Person p2(10); // 调用带一个整数参数的构造函数
    Person p3(p2); // 调用拷贝构造函数
    
    // 2、显示调用构造函数
    Person pp1;
    Person pp2 = Person(10);  // Person(10); 这种写法是匿名对象
    Person pp3 = Person(p2);    // 调用拷贝构造
    
    // 匿名对象，当前行执行完毕后，会立即回收掉匿名对象
    Person(20);
    
    // 注意：不要利用拷贝构造函数初始化匿名对象
    // Person(pp2); Person(p3) 等价于 Person p3
    
    
    // 3、隐士转换法
    Person p4 = 10; // 相当于写了 Person p4 = Person(10);
    Person p5 = p4; // 调用了拷贝构造

    return 0;
}

// 有参构造函数 vs 无参构造函数
// 普通构造函数 vs 拷贝构造函数

// 拷贝构造函数的调用时机：
// 1、使用一个已经创建完毕的对象来初始化一个新对象
// 2、值传递的方式给函数参数传值
// 4、值方式返回局部对象


