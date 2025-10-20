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

class WorkerManager
{

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

  // 统计文件中的人数
  int get_emp_count();

  // 初始化员工
  void init_employees();

  // 删除员工
  void delete_employee();

  // 按照员工编号 _no 查询员工是否存在
  int is_exists(int _no);

  // 修改员工信息
  void modify_employee();

  // 查找员工
  void find_employee();

  // 排序
  void sort_employees();

  // 清空数据
  void clean_file();
};
