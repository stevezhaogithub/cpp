#include "reservation_file.h"

// 封装一个截取字符串到 map 容器的函数
void data_to_map(string _s, map<string, string> &_mp)
{
    string k, v;
    int pos = _s.find(":"); // 如果没有找到 : 则返回 -1
    if (pos >= 0)
    {
        k = _s.substr(0, pos);
        v = _s.substr(pos + 1, _s.size());
        _mp.insert(make_pair(k, v));
    }
}

// 构造函数
ReservationFile::ReservationFile()
{
    // 读取 reservation.txt 文件
    // 周几, 上下午, 学生编号, 学生姓名, 机房编号, 机房状态
    // status: 1预约审核中 2已预约 0取消预约 -1预约失败
    string day, day_part, stu_id, stu_name, lab_id, status;
    this->m_size = 0; // 初始化预约记录条数

    // 创建文件读取流
    ifstream ifs;
    ifs.open(RESERVATION_FILE, ios::in);
    if (ifs.is_open())
    {
        // 打开文件成功，开始读取
        while (ifs >> day && ifs >> day_part && ifs >> stu_id && ifs >> stu_name && ifs >> lab_id && ifs >> status)
        {
            // cout << day << endl;
            // cout << day_part << endl;
            // cout << stu_id << endl;
            // cout << stu_name << endl;
            // cout << lab_id << endl;
            // cout << status << endl;
            // cout << endl;

            map<string, string> mp;
            // DAY:1 PART:2 STU_ID:1 STU_NAME:steve LAB_ID:2 STATUS:1
            // 截取 DAY 部分内容
            data_to_map(day, mp);
            // 截取 PART 部分内容
            data_to_map(day_part, mp);
            // 截取 STU_ID 部分内容
            data_to_map(stu_id, mp);
            // 截取 STU_NAME 部分内容
            data_to_map(stu_name, mp);
            // 截取 LAB_ID 部分内容
            data_to_map(lab_id, mp);
            // 截取 STATUS 部分内容
            data_to_map(status, mp);
            // 将 mp 容器插入到 大的 map 容器中
            m_reservation_data.insert(make_pair(this->m_size, mp));
            this->m_size++;
        }

        ifs.close();

        // // 测试数据是否写进去了
        // for (map<int, map<string, string>>::iterator it = m_reservation_data.begin(); it != m_reservation_data.end(); ++it)
        // {
        //     cout << "key = " << it->first << ", value: " << endl;
        //     // 遍历输出 value 值
        //     for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); ++mit)
        //     {
        //         cout << "\tk = " << mit->first << ",\tv = " << mit->second << endl;
        //     }
        // }
    }
    else
    {
        cout << "预约记录文件读取失败！" << endl;
        ifs.close();
    }
}

// 更新预约记录
void ReservationFile::update_reservation()
{
    // 判断是否有预约记录
    if (this->m_size == 0) // 内存中的集合中没有预约记录，无需写入文件
        return;

    // 如果有记录，则开始更新
    // 1. 将原始数据文件清空
    ofstream ofs(RESERVATION_FILE, ios::out | ios::trunc);
    // 2. 将内存中的数据写入到文件中
    for (map<int, map<string, string>>::iterator it = this->m_reservation_data.begin(); it != this->m_reservation_data.end(); ++it)
    {
        // DAY:1 PART:2 STU_ID:1 STU_NAME:steve LAB_ID:2 STATUS:1
        ofs << "DAY:" << it->second["DAY"] << " ";
        ofs << "PART:" << it->second["PART"] << " ";
        ofs << "STU_ID:" << it->second["STU_ID"] << " ";
        ofs << "STU_NAME:" << it->second["STU_NAME"] << " ";
        ofs << "LAB_ID:" << it->second["LAB_ID"] << " ";
        ofs << "STATUS:" << it->second["STATUS"] << endl;
    }
    // 关闭文件流
    ofs.close();
}
