#include "common.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 绘制主菜单
void show_main_menu() {
    // 先清屏
    clear_screen();
    cout << "-------------------" << endl;
    cout << "1. 记账" << endl;
    cout << "2. 查询" << endl;
    cout << "3. 退出" << endl;
    cout << "请选择(1 - 3): ";
}

// 绘制 "记账" 菜单
void show_accounting_menu() {
    cout << "--------------- 选择记账种类 ---------------" << endl;
    cout << "1. 收入" << endl;
    cout << "2. 支出" << endl;
    cout << "3. 返回主菜单" << endl;
    cout << "请选择(1-3): ";
}

// 进入 "查询" 菜单
void show_query_menu() {
    cout << " --------------- 选择查询条件 --------------- " << endl;
    cout << "1. 统计所有账目" << endl;
    cout << "2. 统计收入" << endl;
    cout << "3. 统计支出" << endl;
    cout << "4. 返回主菜单" << endl;
    cout << "请选择(1-4): ";
}
