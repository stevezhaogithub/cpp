#include "common.h"
#include "account_item.h"

int main()
{
    // 1. 加载数据
    vector<AccountItem> items;
    load_data(items);
    
    // 2. 死循环显示菜单
    bool quit = false;
    while (!quit) {
        // 显示主菜单
        show_main_menu();
        // 读取键盘输入, 并校验输入合法性
        char selected = read_menu_selection(3);
        
        switch (selected) {
            case '1':   // 1 - 记账
                // 进入 "记账" 菜单
                show_accounting_menu();
                
                // 进行 "记账" 操作
                accounting(items);
                break;
            case '2':   // 2 - 查询
                // 进入 "查询" 菜单
                show_query_menu();
                // 进行 "查询" 操作
                do_query(items);
                break;
            case '3':   // 3 - 退出
                cout << "\n确认退出？(Y/N): ";
                if (read_quit_confirm() == 'Y') {
                    quit = true;
                    break;
                }
            default:
                // 其他操作直接 break;
                break;
        }
    }
    
    return 0;
}
