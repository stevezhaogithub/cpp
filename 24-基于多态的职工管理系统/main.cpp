//
//  main.cpp
//  24-基于多态的职工管理系统
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#include "Boss.hpp"
#include "Employee.hpp"
#include "Manager.hpp"
#include "Worker.hpp"
#include "WorkerManager.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{

    WorkerManager wkm;
    int selected = 0;
    while (true)
    {
        wkm.show_menu();
        cout << "请输入您的选择：";
        cin >> selected;
        switch (selected)
        {
        case 0:
            // 退出系统
            wkm.exit_system();
            break;
        case 1:
            // 添加
            wkm.addEmployee();
            break;
        case 2:
            // 显示
            wkm.show_employees();
            break;
        case 3:
            // 删除
            wkm.delete_employee();
            break;
        case 4:
            // 修改
            wkm.modify_employee();
            break;
        case 5:
            // 查找
            wkm.find_employee();
            break;
        case 6:
            // 排序
            wkm.sort_employees();
            break;
        case 7:
            // 清空
            break;
        default:
            // 输入错误
            system("clear");
            cout << "输入错误！" << endl;
            break;
        }
    }
    return 0;
}
