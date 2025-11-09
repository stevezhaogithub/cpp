#include "teacher.h"
// 默认的无参构造函数
Teacher::Teacher()
{
}

// 有参构造函数
Teacher::Teacher(int _tid, string _name, string _pwd)
{
    this->m_name = _name;
    this->m_tid = _tid;
    this->m_passwd = _pwd;
}

// 显示菜单
void Teacher::show_menu()
{
    cout << "欢迎教室代表：" << this->m_name << "登录！" << endl;
    cout << "----------------------\n"
         << endl;
    cout << "1. 查看所有预约" << endl;
    cout << "2. 审核预约" << endl;
    cout << "0. 注销登录" << endl;
    cout << "请选择您要的操作:";
}

// 查看所有预约
void Teacher::show_all_reservations()
{

    ReservationFile rf;
    if (rf.m_size == 0)
    {
        cout << "无预约记录!" << endl;
        cin.ignore();
        cout << "按 Enter 键继续..." << endl;
        cin.get();
        system("clear");
        return;
    }

    // 显示所有人的预约记录
    map<string, string> mp_status_names;
    mp_status_names.insert(make_pair("1", "审核中"));
    mp_status_names.insert(make_pair("2", "已预约"));
    mp_status_names.insert(make_pair("-1", "失败！"));
    mp_status_names.insert(make_pair("0", "已取消"));

    // 显示预约记录
    for (int i = 0; i < rf.m_size; i++)
    {
        cout << (i + 1) << ". ";
        cout << "学号: " << rf.m_reservation_data[i]["STU_ID"] << "    ";
        cout << "预约日期: 周" << rf.m_reservation_data[i]["DAY"] << "    ";
        cout << "预约时间: " << (rf.m_reservation_data[i]["DAY_PART"] == "1" ? "上午" : "下午") << "    ";
        cout << "机房编号: " << rf.m_reservation_data[i]["LAB_ID"] << "    ";
        cout << "预约状态: " << mp_status_names[rf.m_reservation_data[i]["STATUS"]] << "    ";
        cout << "姓名: " << rf.m_reservation_data[i]["STU_NAME"] << endl;
    }
    cin.ignore();
    cout << "按 Enter 键继续..." << endl;
    cin.get();
    system("clear");
}

// 审核预约
void Teacher::review_reservations()
{
    // 1. 如果没有预约, 则无需审核
    ReservationFile rf;
    if (rf.m_size == 0)
    {
        cout << "无预约记录!" << endl;
        cin.ignore();
        cout << "按 Enter 键继续..." << endl;
        cin.get();
        system("clear");
        return;
    }

    // 2. 显示出哪些可以审核的记录（待审核的）
    // 用来显示 预约状态的 字典
    map<string, string> mp_status_names;
    mp_status_names.insert(make_pair("1", "审核中"));
    mp_status_names.insert(make_pair("2", "已预约"));
    mp_status_names.insert(make_pair("-1", "失败！"));
    mp_status_names.insert(make_pair("0", "已取消"));

    cout << "【待审核记录如下】" << endl;

    // 保存待审核的记录的索引
    vector<int> v_pending;
    int index = 0;
    // 显示预约记录
    for (int i = 0; i < rf.m_size; i++)
    {
        if (rf.m_reservation_data[i]["STATUS"] == "1")
        {
            v_pending.push_back(i);
            cout << ++index << ". ";
            cout << "学号: " << rf.m_reservation_data[i]["STU_ID"] << "    ";
            cout << "预约日期: 周" << rf.m_reservation_data[i]["DAY"] << "    ";
            cout << "预约时间: " << (rf.m_reservation_data[i]["DAY_PART"] == "1" ? "上午" : "下午") << "    ";
            cout << "机房编号: " << rf.m_reservation_data[i]["LAB_ID"] << "    ";
            cout << "预约状态: " << mp_status_names[rf.m_reservation_data[i]["STATUS"]] << "    ";
            cout << "姓名: " << rf.m_reservation_data[i]["STU_NAME"] << endl;
        }
    }

    cout << "请输入要审核的预约记录, 0 表示返回: ";
    int selected = 0; // 存储用户选择
    int ret = 0;      // 存储审核结果

    while (true)
    {
        cin >> selected;
        if (selected == 0)
        {
            break;
            ;
        }
        else if (selected > 0 && selected < v_pending.size())
        {
            // 开始审核
            cout << "请输入审核结果:" << endl;
            cout << "1. 通过" << endl;
            cout << "2. 不通过" << endl;
            cin >> ret; // 通过 ret = 1
            rf.m_reservation_data[v_pending[selected - 1]]["STATUS"] = (ret == 1) ? "2" : "-1";
            // 更新记录
            rf.update_reservation();
            cout << "审核完毕！" << endl;
            break;
        }
        else
        {
            cout << "输入有误，请重新输入！" << endl;
        }
    }
    cin.ignore();
    cout << "按 Enter 键继续..." << endl;
    cin.get();
    return;
}
