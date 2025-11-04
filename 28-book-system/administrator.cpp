#include "administrator.h"
// 默认的无参数构造函数
Administrator::Administrator()
{
}

// 有参数构造函数
Administrator::Administrator(string _name, string _pwd)
{
    this->m_name = _name;
    this->m_passwd = _pwd;
}

// 显示管理员菜单
void Administrator::show_menu()
{
    // 显示管理员菜单
    cout << "欢迎管理员: " << this->m_name << " 登录！" << endl;
    cout << "\t\t\t1. 添加账号" << endl;
    cout << "\t\t\t2. 查看账号" << endl;
    cout << "\t\t\t3. 查看机房" << endl;
    cout << "\t\t\t4. 清空预约" << endl;
    cout << "\t\t\t0. 注销登录" << endl;
    cout << "请选择您的操作: " << endl;
}

// 添加账号
void Administrator::add_account()
{
}

// 查看账号
void Administrator::show_accounts()
{
}

// 查看机房信息
void Administrator::show_rooms()
{
}

// 清空预约
void Administrator::clear_reservations()
{
}
