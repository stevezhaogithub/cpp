#pragma once
// #include "common.h"
#include <vector>

class AccountItem
{
public:
    // 1. 类型
    std::string item_type;
    // 2. 金额
    double amount;
    // 3. 备注
    std::string remark;
};

// ------------------- 针对账目各种操作的函数声明 --------------------

// 加载全部账目数据
void load_data(std::vector<AccountItem> &_items);
