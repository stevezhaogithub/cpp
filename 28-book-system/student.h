#pragma once
#include <iostream>
#include "identity.h"
using namespace std;

class Student : public Identity
{
public:
    // 默认构造函数
    Student();

    // 有参构造函数
    Student(int _id, string _name, string _pwd);

    // 菜单界面(继承自父类的纯虚函数)，在该 Student 类中要实现这个方法
    virtual void show_menu();

    // 申请预约
    void book_room();

    // 查看我的预约
    void show_my_reservation();

    // 查看所有人的预约
    void show_reservations();

    // 取消预约
    void cancel_reservation();

    // 学生学号
    int m_id;
};
