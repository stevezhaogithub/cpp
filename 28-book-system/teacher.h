#pragma once
#include <iostream>
#include "identity.h"
using namespace std;

class Teacher : public Identity
{
public:
    // 默认的无参构造函数
    Teacher();

    // 有参构造函数
    Teacher(int _tid, string _name, string _pwd);

    // 显示菜单
    virtual void show_menu();

    // 查看所有人的预约
    void show_all_reservations();

    // 审核预约
    void review_reservations();

    // 教师编号
    int m_tid;
};