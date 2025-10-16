//
//  Boss.cpp
//  24-基于多态的职工管理系统
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#include "Boss.hpp"

Boss::Boss(int _no, string _name, int _deptNo) {
    this->m_no = _no;
    this->m_name = _name;
    this->m_dept_no = _deptNo;
}

void Boss::showInfo() {
    cout << "职工编号：" << this->m_no << "\t\t职工姓名：" << this->m_name
         << "\t\t部门名称：" << this->getDeptName()
         << "\t\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName() { return string("老板"); }
