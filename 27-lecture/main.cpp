/*
    1. 提供菜单界面与用户交互
    2. 对比赛流程进行控制
    3. 与文件进行交互

*/
#include <iostream>
#include <string>
#include <ctime>
#include "manager.h"
using namespace std;

int main()
{

    srand((unsigned int)time(NULL));

    SpeechManager sm;

    // // 测试
    // for (map<int, Speaker>::iterator it = sm.m_speakers.begin(); it != sm.m_speakers.end(); ++it)
    // {
    //     cout << "编号：" << it->first << "姓名：" << it->second.m_name << "得分1：" << it->second.m_scores[0] << "得分2：" << it->second.m_scores[1] << endl;
    // }

    int selected = -1;
    while (true)
    {
        // 显示菜单
        sm.show_menu();
        cout << "请选择数字：";
        // 接收用户的输入
        cin >> selected;
        cin.ignore(); // 忽略缓冲区中的 \n
        switch (selected)
        {
        case 0:
            // 退出系统
            sm.exit_system();
            break;
        case 1:
            // 开始比赛
            sm.start_contest();
            break;
        case 2:
            // 查看往届比赛记录
            break;
        case 3:
            // 清空比赛记录
            break;
        default:
            // 输入有误
            cout << "请选择正确的选项！" << endl;
            break;
        }
    }

    return 0;
}