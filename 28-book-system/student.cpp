#include "student.h"

// 默认构造函数
Student::Student()
{
}

// 有参构造函数
Student::Student(int _id, string _name, string _pwd)
{
    this->m_id = _id;
    this->m_name = _name;
    this->m_passwd = _pwd;
    // 初始化机房信息
    ifstream ifs;
    ifs.open(ROOM_FILE, ios::in);
    if (ifs.is_open())
    {
        // 打开机房文件成功，开始读取
        ComputerLab _cmputer;
        while (ifs >> _cmputer.m_lab_id && ifs >> _cmputer.m_max_computers)
        {
            this->v_stu_labs.push_back(_cmputer);
        }
        // 关闭文件流
        ifs.close();
    }
    else
    {
        cout << "打开机房文件失败！" << endl;
        ifs.close();
    }
}

// 菜单界面
void Student::show_menu()
{
    cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
    cout << "----------------------\n"
         << endl;
    cout << "1. 申请预约" << endl;
    cout << "2. 查看我的预约" << endl;
    cout << "3. 查看所有预约" << endl;
    cout << "4. 取消预约" << endl;
    cout << "0. 注销登录" << endl;
}

// 申请预约
void Student::book_room()
{
    int day;      // 保存周几
    int day_part; // 保存上午 or 下午
    int lab_id;   // 保存机房编号

    cout << "机房开放时间为: 周一 至 周五" << endl;

    // 输入日期
    cout << "请输入申请预约的时间: " << endl;
    cout << "1.周一  2.周二  3.周三  4.周四  5.周五" << endl;
    while (true)
    {
        cin >> day;
        if (day >= 1 && day <= 5)
        {
            break;
        }
        cout << "输入有误, 请重新输入!" << endl;
    }

    // 输入时间段
    cout << "请输入预约时间段: " << endl;
    cout << "1.上午  2.下午" << endl;
    while (true)
    {
        cin >> day_part;
        if (day_part == 1 || day_part == 2)
        {
            break;
        }
        cout << "输入有误, 请重新输入!" << endl;
    }

    // 输入机房信息
    cout << "请选择机房: " << endl;
    for (int i = 0; i < this->v_stu_labs.size(); i++)
    {
        cout << this->v_stu_labs[i].m_lab_id << " 号机房的容量为: " << this->v_stu_labs[i].m_max_computers << endl;
    }
    // 判断输入的机房编号是否合法
    while (true)
    {
        cin >> lab_id;
        if (lab_id >= this->v_stu_labs[0].m_lab_id && lab_id <= this->v_stu_labs[this->v_stu_labs.size() - 1].m_lab_id)
        {
            break;
        }
        cout << "输入有误, 请重新输入!" << endl;
    }

    cout << "预约审核中!" << endl;

    // 向预约文件中写入数据 reservation.txt
    ofstream ofs;
    ofs.open(RESERVATION_FILE, ios::out | ios::app);
    if (ofs.is_open())
    {
        // 成功打开了文件, 开始写入
        ofs << "DAY:" << day << " ";
        ofs << "PART:" << day_part << " ";
        ofs << "STU_ID:" << this->m_id << " ";
        ofs << "STU_NAME:" << this->m_name << " ";
        ofs << "LAB_ID:" << lab_id << " ";
        ofs << "STATUS:" << 1 << endl;
        ofs.close();

        cin.ignore();
        cout << "按 Enter 键继续..." << endl;
        cin.get();
        system("clear");
    }
    else
    {
        cout << "文件打开失败！" << endl;
        ofs.close();
    }
}

// 查看所有人的预约
void Student::show_reservations()
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
    mp_status_names.insert(make_pair("-1", "预约失败"));
    mp_status_names.insert(make_pair("0", "取消预约"));

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
}
// 查看我的预约
void Student::show_my_reservation()
{
    // 会调用构造函数
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
    map<string, string> mp_status_names;

    mp_status_names.insert(make_pair("1", "审核中"));
    mp_status_names.insert(make_pair("2", "已预约"));
    mp_status_names.insert(make_pair("-1", "预约失败"));
    mp_status_names.insert(make_pair("0", "取消预约"));

    // 显示预约记录
    for (int i = 0; i < rf.m_size; i++)
    {
        // C++ string 对象如何转为 int 类型
        // 1. string.c_str() 将 string 对象转为 c 字符串
        // 2. atoi(const chat *) 转为 int

        // 判断文件中读取的预约记录的学号是否与当前登录的学生的学号一致
        // 如果一致, 则显示该条预约记录
        if (this->m_id == atoi(rf.m_reservation_data[i]["STU_ID"].c_str()))
        {
            cout << "预约日期: 周" << rf.m_reservation_data[i]["DAY"] << "    ";
            cout << "预约时间: " << (rf.m_reservation_data[i]["DAY_PART"] == "1" ? "上午" : "下午") << "    ";
            cout << "机房编号: " << rf.m_reservation_data[i]["LAB_ID"] << "    ";
            cout << "预约状态: " << mp_status_names[rf.m_reservation_data[i]["STATUS"]] << endl;
        }
    }
}

// 取消预约
void Student::cancel_reservation()
{
}