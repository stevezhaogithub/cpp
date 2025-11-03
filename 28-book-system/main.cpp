#include <iostream>
using namespace std;
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
            break;
        case 2:
            // 老师身份
            break;
        case 3:
            // 管理员身份
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