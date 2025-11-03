#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <deque>
#include <numeric>
#include <iomanip>
#include <fstream>
#include "speaker.h"
using namespace std;

// 设计演讲比赛的管理类
class SpeechManager
{
public:
    // 构造函数
    SpeechManager();

    // 析构函数
    ~SpeechManager();

    // 初始化容器和属性
    void init_data();
    // 显示菜单功能
    void show_menu();

    // 退出系统
    void exit_system();

    // 属性
    // 保存第一轮 12 位选手的编号
    vector<int> v1;
    // 保存第二轮 6 位选手的编号(第一轮晋级的 6 位选手)
    vector<int> v2;

    // 保存胜出的前3名选手的编号
    vector<int> v_victory;

    // 存放 <编号,选手> 键值对的容器
    map<int, Speaker> m_speakers;

    // 记录比赛轮数的变量
    int m_round_count;

    // 创建选手
    void createSpeakers();

    // 开始演讲比赛
    void start_contest();

    // 抽签
    void draw_lots();

    // 开始淘汰赛
    void start_knock_out();

    // 显示得分
    void show_scores();

    // 将比赛数据写入文件
    void save_records();

    // 加载记录分数(从文件中读取)
    void load_records();

    // 文件为空的标记
    bool is_file_empty;

    // 往届记录
    map<int, vector<string>> m_records;

    // 查看记录功能
    void show_records();

    // 清空记录
    void clear_records();
};