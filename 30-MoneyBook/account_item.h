#pragma once
#include "common.h"

// 定义结构体类型
struct AccountItem
{
    // 1. 类型
    string item_type;
    // 2. 金额
    double amount;
    // 3. 备注
    string remark;
};


// ------------------- 针对账目各种操作的函数声明 --------------------


// 加载全部账目数据
void load_data(vector<AccountItem> & _items);




