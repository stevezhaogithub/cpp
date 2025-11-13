#include "common.h"

// 读取键盘输入, 并校验合法性
char read_menu_selection(int _range) {
    while (true) {
        string text;
        // 从命令行读取一行输入
        getline(cin, text);
        // 判断长度
        if (text.size() == 1 && (text[0] - '0') >= 0 &&
            (text[0] - '0') <= _range) {
            return text[0];
        }
        cout << "输入错误, 请重新输入！" << endl;
    }
}

// 确认退出
char read_quit_confirm() {
    while (true) {
        // 读取用户输入的整行信息
        string line;
        getline(cin, line);
        if (line == "Y" || line == "y" || line == "n" || line == "N") {
            return toupper(line[0]);
        } else {
            cout << "输入不合法, 请重新输入!" << endl;
        }
    }
}
