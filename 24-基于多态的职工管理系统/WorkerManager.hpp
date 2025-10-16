//
//  WorkerManager.hpp
//  24-基于多态的职工管理系统
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#pragma once
#include <iostream>
#include "Worker.hpp"
using namespace std;

class WorkerManager {

  public:
    // 员工总人数
    int m_count;
    // 员工数组指针
    Worker **m_employees;

  public:
    // 构造函数
    WorkerManager();
    // 析构函数
    ~WorkerManager();
    // 显示系统菜单
    void show_menu();

    // 退出系统
    void exit_system();
    
    // 添加员工
    void addEmployee();
    
    
    // 将数据保存到文件中
    void save();
    
    
    // 判断文件是否为空
    bool is_file_empty;
    
    // 显示员工
    void show_employees();
};
