#include <iostream>
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

int main() {
    // 1、通过传统调用构造函数初始化属性
    Person p(10, 20, 30);

    //    // 2、通过初始化列表初始化属性
    //    Person p;
    p.show();
    return 0;
}
