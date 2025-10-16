//
//  Manager.cpp
//  24-基于多态的职工管理系统
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#include "Manager.hpp"

Manager::Manager(int _no, string _name, int _deptNo) {
    this->m_no = _no;
    this->m_name = _name;
    this->m_dept_no = _deptNo;
}
void Manager::showInfo() {
    cout << "员工编号：" << this->m_no << "\t\t员工姓名：" << this->m_name
         << "\t\t员工部门：" << this->getDeptName() << "\t\t岗位职责：发布任务"
         << endl;
}
string Manager::getDeptName() {
    return string("经理");
}
