#include "student.h"

// 默认构造函数
Student::Student()
{
}

// 有参构造函数
Student::Student(int _id, string _name, string _pwd)
{
    this->m_id = _id;
    this->m_name = _name;
    this->m_passwd = _pwd;
}

// 菜单界面
void Student::show_menu()
{
    cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
    cout << "----------------------\n"
         << endl;
    cout << "1. 申请预约" << endl;
    cout << "2. 查看我的预约" << endl;
    cout << "3. 查看所有预约" << endl;
    cout << "4. 取消预约" << endl;
    cout << "0. 注销登录" << endl;
}

// 申请预约
void Student::book_room()
{
}

// 查看所有人的预约
void Student::show_reservations()
{
}
// 查看我的预约
void Student::show_my_reservation()
{
}

// 取消预约
void Student::cancel_reservation()
{
}