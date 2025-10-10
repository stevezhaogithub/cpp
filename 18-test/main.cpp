
#include <iostream>
#include <string>
using namespace std;

class Person {
  public:
    Person() { cout << "默认构造函数" << endl; }

    Person(int age, int height) {
        m_age = age;
        m_height = new int(height);
        cout << "带参数的构造函数" << endl;
    }

    ~Person() { cout << "析构函数" << endl; }
    int m_age;
    int *m_height;
};

void test01() {
    Person p1(18, 160);
    cout << "p1的年龄为：" << p1.m_age << " 身高为：" << p1.m_height << endl;
    Person p2(p1);
    cout << "p2的年龄为：" << p2.m_age << " 身高为：" << p2.m_height << endl;
}

int main() {

    test01();
    return 0;
}
