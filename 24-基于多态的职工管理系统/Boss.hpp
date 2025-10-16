//
//  Boss.hpp
//  24-基于多态的职工管理系统
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#pragma once
#include <iostream>
#include <string>
#include "Worker.hpp"
using namespace std;

class Boss : public Worker {
  public:
    Boss(int _no, string _name, int _deptNo);
    virtual void showInfo();
    virtual string getDeptName();
};
