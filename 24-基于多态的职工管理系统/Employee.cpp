//
//  Employee.cpp
//  LearnCPP
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#include "Employee.hpp"
#include <iomanip>

// 实现构造函数
Employee::Employee(int _no, string _name, int _deptNo) {
    this->m_no = _no;
    this->m_name = _name;
    this->m_dept_no = _deptNo;
}

// 显示个人信息函数
void Employee::showInfo() {
    cout << "员工编号：" << setfill(' ') << left << setw(10) << this->m_no
         << "员工姓名：" << setfill(' ') << left << setw(20) << this->m_name
         << "员工部门编号：" << this->m_dept_no << endl;
}
// 获取部门名称函数
string Employee::getDeptName() {
    // 直接写 "zifuchuan "是 const char * 类型，不是 string类型
    return string("员工");
}
