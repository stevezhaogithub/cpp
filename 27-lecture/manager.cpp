#include "manager.h"
// 构造函数
SpeechManager::SpeechManager()
{
    // 初始化容器和属性
    this->init_data();
    this->createSpeakers();
}

// 析构函数
SpeechManager::~SpeechManager()
{
}

// 初始化容器和属性
void SpeechManager::init_data()
{
    // 1. 容器设置为空
    this->v1.clear();
    this->v2.clear();
    this->v_victory.clear();
    this->m_speakers.clear();

    // 2. 初始化比赛轮数
    this->m_round_count = 1;
}

// 显示菜单功能
void SpeechManager::show_menu()
{
    cout << "-------------------------------------------------" << endl;
    cout << "***************** 欢迎参加演讲比赛 ***************" << endl;
    cout << "***************** 1. 开始演讲比赛 ****************" << endl;
    cout << "***************** 2. 查看往届记录 ****************" << endl;
    cout << "***************** 3. 清空比赛记录 ****************" << endl;
    cout << "***************** 0. 退出比赛程序 ****************" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "请选择数字：";
}

// 退出系统
void SpeechManager::exit_system()
{
    cout << "欢迎下次使用!" << endl;
    exit(0);
}

// 创建选手
void SpeechManager::createSpeakers()
{
    // 1. 创建 12 名选手
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++)
    {
        // 选手名字拼接
        string _name = string("选手") + nameSeed[i];
        // 创建选手对象
        Speaker sp;
        sp.m_name = _name;
        // 初始化选手得分
        for (int j = 0; j < 2; j++)
        {
            sp.m_scores[j] = 0;
        }

        // 创建选手编号，并且放入到 v1 容器中
        this->v1.push_back(i + 10001);

        // 将选手编号和选手对象放入到 map 容器中
        this->m_speakers.insert(make_pair(i + 10001, sp));
    }
}