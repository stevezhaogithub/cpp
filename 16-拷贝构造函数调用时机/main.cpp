//
//  main.cpp
//  16-拷贝构造函数调用时机
//
//  Created by steve xiaohu zhao on 2025/10/9.
//

#include <iostream>
using namespace std;
// 拷贝构造函数的调用时机：
// 1、使用一个已经创建完毕的对象来初始化一个新对象
// 2、值传递的方式给函数参数传值
// 4、值方式返回局部对象

class Person {

  private:
    int age;

  public:
    Person() { cout << "Person默认构造函数被调用了！" << endl; }
    Person(int _age) {
        age = _age;
        cout << "有参构造函数被调用了！" << endl;
    }
    Person(const Person &p) { cout << "拷贝构造函数被调用了！" << endl; }

    ~Person() { cout << "Person析构函数被调用了" << endl; }
};

void doWork(Person p1) {}
// 2、值传递的方式给函数参数传值
void test02() {
    Person p;
    // 把对象 p 传递给 doWork() 中的参数 p1 时，调用了拷贝构造函数
    doWork(p);
}

int main(int argc, const char *argv[]) {

    // 2、值传递的方式给函数参数传值
    test02();
    return 0;
}
