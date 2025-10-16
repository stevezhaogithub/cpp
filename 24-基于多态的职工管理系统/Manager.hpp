//
//  Manager.hpp
//  24-基于多态的职工管理系统
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#pragma once
#include "Worker.hpp" // 包含父类头文件
#include <iostream>
#include <string>
using namespace std;

// 创建经理类
class Manager : public Worker {
  public:
    // 构造函数
    Manager(int _no, string _name, int _deptNo);

    // 显示个人信息
    virtual void showInfo();

    // 返回部门名称
    virtual string getDeptName();
};
