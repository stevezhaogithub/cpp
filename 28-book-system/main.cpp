#include <iostream>
#include <fstream>
#include <string>
#include "identity.h"
#include "global_file.h"
using namespace std;

// 登录功能
/**
 * _fname: 操作文件的名称
 * _role: 操作身份的类型（角色)
 */
void login(string _fname, int _role)
{
    // 创建一个父类指针，将来用于指向子类对象
    Identity *person = NULL;

    // 读文件
    ifstream ifs;
    ifs.open(_fname, ios::in);
    // 判断文件是否存在
    if (!ifs.is_open())
    {
        // 文件打开失败
        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }
    // 准备接收用户信息
    int _id = 0;
    string _name, _pwd;

    // 判断身份
    switch (_role)
    {
    case 1:
        cout << "请输入学号: " << endl;
        cin >> _id;
        break;
    case 2:
        cout << "请输入职工号: " << endl;
        cin >> _id;
        break;
    }

    cout << "请输入用户名: ";
    cin >> _name;
    cout << "请输入密码: ";
    cin >> _pwd;
    // 验证身份
    if (_role == 1)
    {
        // 学生身份验证
    }
    else if (_role == 2)
    {
        // 教师身份验证
    }
    else if (_role == 3)
    {
        // 管理员身份验证
    }
    cout << "验证登录失败！" << endl;
    cin.ignore();
    cout << "按 Enter 键继续..." << endl;
    cin.get();
    system("clear");
}

int main()
{
    // 接收用户的选择
    int selected;

    while (true)
    {
        cout << "==================== " << "欢迎来到太原理工大学机房预约系统" << " ====================" << endl;
        cout << endl
             << "请输入您的身份" << endl;
        cout << "\t\t--------------------------\n";
        cout << "\t\t|                        |\n";
        cout << "\t\t|     1.学生代表         |\n";
        cout << "\t\t|                        |\n";
        cout << "\t\t|     2.老    师         |\n";
        cout << "\t\t|                        |\n";
        cout << "\t\t|     3.管 理 员         |\n";
        cout << "\t\t|                        |\n";
        cout << "\t\t|     0.退   出          |\n";
        cout << "\t\t|                        |\n";
        cout << "\t\t--------------------------\n";
        cout << "输入您的选择:";
        // 读取到用户的输入
        cin >> selected;

        // 通过 Switch 判断用户的输入选择
        switch (selected)
        {
        case 1:
            // 学生身份
            login(STUDENT_FILE, 1);
            break;
        case 2:
            // 老师身份
            login(TEACHER_FILE, 2);
            break;
        case 3:
            // 管理员身份
            login(ADMIN_FILE, 3);
            break;
        case 0:
            // 退出程序
            cout << "欢迎下次使用！" << endl;
            exit(0);
            break;
        default:
            // 输出错误
            cout << "您的输入不合法, 请重新输入！" << endl;
            cin.ignore();
            cout << "按 Enter 键继续..." << endl;
            cin.get();
            system("clear");
            break;
        }
    }

    return 0;
}
