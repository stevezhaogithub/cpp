#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "global_file.h"
using namespace std;

class ReservationFile
{
public:
    // 构造函数
    ReservationFile();

    // 更新预约记录
    void update_reservation();

    // 记录预约条数
    int m_size;

    // 记录所有预约信息的容器
    // key 表示第几条记录
    // value 表示具体的记录键值对信息
    map<int, map<string, string>> m_reservation_data;
};
