//
//  Worker.hpp
//  LearnCPP
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#pragma once
#include <iostream>
#include <string>
using namespace std;

// 员工抽象类, 因为该抽象类没有实现，所以不需要创建 .cpp 文件
class Worker {
  public:
    // 显示员工详细信息（纯虚函数）
    virtual void showInfo() = 0;
    // 显示岗位信息（纯虚函数)
    virtual string getDeptName() = 0;

    int m_no;      // 员工编号
    string m_name; // 员工姓名
    int m_dept_no; // 员工所在部门编号
};
