#pragma once
#include <iostream>
#include <fstream>
#include "identity.h"
#include "global_file.h"
using namespace std;

// 管理员类
class Administrator : public Identity
{
public:
    // 默认的无参数构造函数
    Administrator();

    // 有参数构造函数
    Administrator(string _name, string _pwd);

    // 显示菜单
    virtual void show_menu();

    // 添加账号
    void add_account();

    // 查看账号
    void show_accounts();

    // 查看机房信息
    void show_rooms();

    // 清空预约
    void clear_reservations();
};