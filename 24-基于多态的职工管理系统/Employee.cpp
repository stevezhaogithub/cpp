//
//  Employee.cpp
//  LearnCPP
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#include "Employee.hpp"

// 实现构造函数
Employee::Employee(int _no, string _name, int _deptNo) {
    this->m_no = _no;
    this->m_name = _name;
    this->m_dept_no = _deptNo;
}

// 显示个人信息函数
void Employee::showInfo() {
    cout << "职工编号：" << this->m_no << "\t\t职工姓名：" << this->m_name
         << "\t\t部门名称：" << this->getDeptName()
         << "\t\t岗位职责：完成经理交给的任务" << endl;
}
// 获取部门名称函数
string Employee::getDeptName() {
    // 直接写 "zifuchuan "是 const char * 类型，不是 string类型
    return string("员工");
}
