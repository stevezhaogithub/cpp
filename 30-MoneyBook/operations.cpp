#include "account_item.h"
#include "common.h"

// 加载数据
void load_data(vector<AccountItem> &_items)
{
    // 读取文件
    ifstream ifs(FILE_NAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开错误！" << endl;
        return;
    }

    // 逐行读取每一条账目, 包装成 AccountItem
    AccountItem item;

    while (ifs >> item.item_type && ifs >> item.amount && ifs >> item.remark)
    {
        _items.push_back(item);
    }

    // 关闭
    ifs.close();
}

// 进行 "记账" 操作
void accounting(vector<AccountItem> &_items)
{
    
}

/**

 ifstream ifs(filename,ios::in);
 一、ifs 逐词读取
 string words;
 ifs >> words;

 二、ifs 逐行读取
 string line;
 getline(ifs, line);

 三、ifs 逐字符读取
 char ch;
 ifs.get(ch);


 */
