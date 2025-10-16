//
//  main.cpp
//  12-类和对象
//
//  Created by steve xiaohu zhao on 2025/9/30.
//

#include <iostream>
#include <string>
using namespace std;

const double PI = 3.1415926;

/*
    1、设计一个圆类，计算圆的周长和面积
    2、设计一个学生类：
    - 属性：姓名、学号
    - 方法：显示学生的姓名和学号
*/

class Circle {
  public:
    // 圆的半径
    int r;
    // 计算圆的周长
    double calculate_circumference() { return 2 * PI * r; }
};

class Student {
  private:
    int age;

  public:
    string sname;
    string sno;
    void show() {
        cout << "姓名：" << sname << ", 学号：" << sno << "年龄：" << age
             << endl;
    }
    void setAge(int _age) { age = _age; }
};

/*
    访问修饰符：public、private、protected
*/

class Person {
  public:
    string name;

  protected:
    string car;

  private:
    string password;

  public:
    void loadData() {
        name = "张三";
        car = "BMW";
        password = "123456";
    }
};

class Teacher {
  public:
    string t_name;

  protected:
    string t_car;

  private:
    string t_password;

  public:
    void set_data() {
        t_name = "张三";
        t_car = "BMW320";
        t_password = "123456";
    }
};

class C1 {

    // 默认访问修饰符是 private
    int m_A;
};

struct S1 {
    // 默认访问修饰符是 public
    int m_B;
};

// 自定义成元的读写属性
class Employee {
  private:
    // 可读可写
    string m_name;

    // 只读
    int m_age;
    // 只写
    string m_idol;

  public:
    // 姓名可读可写
    string get_name() { return m_name; }
    void set_name(string name) { m_name = name; }

    // 年龄只读
    int get_age() { return m_age; }

    // idol 只写
    void set_idol(string idol) { m_idol = idol; }
};

int main(int argc, const char *argv[]) {

    Employee employee;
    employee.set_name("张小四");
    employee.set_idol("王一博");
    cout << employee.get_name() << employee.get_age() << endl;
    // cout << employee.get_name() << employee.get_age() << employee.get_idol()
    // << endl;

    Person p1;
    //    cout << p1.name << p1.car << p1.password << endl;

    // 通过 Circle 类创建一个对象（实例化一个对象）
    Circle circle;
    circle.r = 10;
    double cmf = circle.calculate_circumference();
    cout << "圆的周长是：" << cmf << endl;

    // 实例化学生类
    Student stu;
    stu.sname = "赵晓虎";
    stu.sno = "2022006329";
    stu.setAge(100);
    stu.show();

    Student s2;
    s2.sno = "1001000101";
    s2.sname = "bob";
    s2.setAge(18);
    s2.show();

    Teacher t1;
    t1.t_name = "李四";

    // protected 类外部无法访问
    // t1.t_car = "volvol";
    // private 类外部无法访问
    // t1.t_password = "999";

    return 0;
}
