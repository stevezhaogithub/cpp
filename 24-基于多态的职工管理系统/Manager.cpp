//
//  Manager.cpp
//  24-基于多态的职工管理系统
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#include "Manager.hpp"
#include <iomanip>

Manager::Manager(int _no, string _name, int _deptNo) {
    this->m_no = _no;
    this->m_name = _name;
    this->m_dept_no = _deptNo;
}
void Manager::showInfo() {
    cout << "员工编号：" << setfill(' ') << left << setw(10) << this->m_no
         << "员工姓名：" << setfill(' ') << left << setw(20) << this->m_name
         << "员工部门编号：" << this->m_dept_no << endl;
}
string Manager::getDeptName() { return string("经理"); }
