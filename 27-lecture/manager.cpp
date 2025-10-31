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

// 抽签
void SpeechManager::draw_lots()
{
    cout << "第 " << this->m_round_count << " 轮的选手正在抽签!" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "抽签后的演讲顺序如下：" << endl;

    if (this->m_round_count == 1)
    {
        // 第一轮比赛
        random_device rd;
        mt19937 g(rd());
        // 把 v1 容器顺序打乱
        shuffle(v1.begin(), v1.end(), g);

        for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        // 第二轮比赛
        random_device rd;
        mt19937 g(rd());
        // 把 v2 容器顺序打乱
        shuffle(v2.begin(), v2.end(), g);

        for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl;
}

// 开始演讲比赛
void SpeechManager::start_contest()
{
    // 1. 第一轮比赛
    // 1.1 抽签
    draw_lots();

    // 1.2 比赛
    start_knock_out();

    // 1.3 显示晋级结果

    // 2. 第二轮比赛
    // 2.1 抽签
    // 2.2 比赛
    // 2.3 显示最终结果

    // 4. 保存分数到文件中
}

// 开始淘汰赛
void SpeechManager::start_knock_out()
{
    cout << "---------- 第 " << this->m_round_count << " 轮比赛正式开始！----------" << endl;
    vector<int> v_source; // 比赛选手容器
    if (this->m_round_count == 1)
    {
        // 第1轮比赛
        v_source = v1;
    }
    else
    {
        // 第2轮比赛
        v_source = v2;
    }

    // 遍历所有选手进行比赛
    for (vector<int>::iterator it = v_source.begin(); it != v_source.end(); ++it)
    {
        // 评委打分 deque 容器
        deque<double> deq;
        for (int i = 0; i < 10; i++)
        {
            // 产生一个 [60,100] 的随机数
            double _score = (rand() % 401 + 600) / 10.0f;
            // 设置每个小数显示2位小数
            cout << "得分：" << fixed << setprecision(2) << _score << " ";
            deq.push_back(_score);
        }
        cout << endl;
        // 将 deq 中的数据降序排序
        sort(deq.begin(), deq.end(), greater<double>());
        // 去除最高分
        deq.pop_front();
        // 去除最低分
        deq.pop_back();

        // 累加总分
        double sum = accumulate(deq.begin(), deq.end(), 0.0);
        // 计算平均分
        double avg = sum / static_cast<double>(deq.size());

        // 输出每个人的平均分
        cout << "编号: " << *it << ", 姓名: " << this->m_speakers[*it].m_name << ", 平均分: " << avg << endl
             << endl;

        // 将平均分放入到 map 容器里
        this->m_speakers[*it].m_scores[this->m_round_count - 1] = avg;
    }
}