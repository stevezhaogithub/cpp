//
//  main.cpp
//  17-test构造函数
//
//  Created by steve xiaohu zhao on 2025/10/10.
//

#include <iostream>
#include <string>
using namespace std;

class Person {
  public:
    int m_age;
    string m_name;
    void show() { cout << "name = " << m_name << "-- age = " << m_age << endl; }
};

int main(int argc, const char *argv[]) {
    Person p1;
    p1.m_age = 18;
    p1.m_name = "steve";

    // 系统有默认的拷贝构造函数
    Person p2(p1);

    p2.show();
    return 0;
}
