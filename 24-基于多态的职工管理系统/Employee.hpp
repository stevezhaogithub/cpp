//
//  Employee.hpp
//  LearnCPP
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#pragma once
#include "Worker.hpp"
#include <iostream>
#include <string>
using namespace std;

// Employee 普通员工类，继承自 Woker 抽象类
class Employee : public Worker {
  public:
    // 构造函数
    Employee(int _no, string name, int deptNo);
    // 显示个人信息(自类重写父类虚函数的时候，自类中的 virtual
    // 关键字可删可不删）
    virtual void showInfo();
    // 获取岗位名称
    string getDeptName();
};
