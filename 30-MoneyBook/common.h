#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// 定义全局生效的常量
#define INCOME "收入"
#define EXPENSE "支出"
#define FILE_NAME "./records.txt"

using namespace std;


// ----------------- 通用功能性函数声明 -----------------

// 加载数据
void load_data(vector<AccountItem> & _item);

// 1. 绘制菜单的函数

// 显示主菜单
void show_main_menu();

// 读取键盘输入, 并校验合法性
void read_menu_selection(int _range);

// 显示 "记账" 菜单
void show_accounting_menu();


// 进行 "记账" 操作
void accounting(vector<AccountItem> &_items);


// 进入 "查询" 菜单
void show_query_menu();

// 进行 "查询" 操作
void do_query(const vector<AccountItem> &_items);

// 确认退出
char read_quit_confirm();

// 2. 读取键盘输入进行合法性校验的函数




