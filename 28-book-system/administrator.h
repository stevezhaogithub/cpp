#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "identity.h"
#include "global_file.h"
#include "student.h"
#include "teacher.h"
#include "computer_labs.h"
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

    /**
     * 添加账号的时候判断是否有重复
     * 1. 初始化容器
     * 2. 学生容器
     * 3. 教师容器
     */
    // 1. 初始化容器
    void init_vector();
    // 2. 学生容器
    vector<Student> v_stu;
    // 3. 教师容器
    vector<Teacher> v_tea;

    // 检测是否重复
    bool check_repeat(int _id, int _role);

    // 机房容器
    vector<ComputerLab> v_labs;

    // 初始化机房信息
    void init_labs();
};
