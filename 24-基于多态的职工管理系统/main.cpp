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

int main(int argc, const char *argv[]) {

    //    Worker *wk = NULL;
    //    wk = new Employee(1001, "张三", 9001);
    //    wk->showInfo();
    //
    //    Worker *wk1 = NULL;
    //    wk1 = new Manager(2001, "李四", 8001);
    //    wk1->showInfo();
    //
    //    Worker *wk2 = NULL;
    //    wk2 = new Boss(3001, "王五", 7001);
    //    wk2->showInfo();

    WorkerManager wkm;
    int selected = 0;
    while (true) {
        wkm.show_menu();
        cout << "请输入您的选择：";
        cin >> selected;
        switch (selected) {
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
            break;
        case 3:
            // 删除
            break;
        case 4:
            // 修改
            break;
        case 5:
            // 查找
            break;
        case 6:
            // 排序
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

    //    // 防止窗口立即关闭
    //    cin.get();
    //    cin.get();
    return 0;
}
