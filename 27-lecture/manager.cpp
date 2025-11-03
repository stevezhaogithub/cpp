#include "manager.h"
// 构造函数
SpeechManager::SpeechManager()
{
    // 初始化容器和属性
    this->init_data();
    this->createSpeakers();

    // 加载往届记录
    this->load_records();
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
    // 将加载的 records 记录集合也清空
    this->m_records.clear();

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
    cout << "按 Enter 键继续..." << endl;
    cin.get();
}

// 开始演讲比赛
void SpeechManager::start_contest()
{
    // --------- 重新初始化数据 ------------
    // 初始化容器和属性
    this->init_data();
    this->createSpeakers();

    // 1. 第一轮比赛
    // 1.1 抽签
    draw_lots();

    // 1.2 比赛
    start_knock_out();

    // 1.3 显示晋级结果
    show_scores();

    // 2. 第二轮比赛
    this->m_round_count++;

    // 2.1 抽签
    draw_lots();
    // 2.2 比赛
    start_knock_out();

    // 2.3 显示最终结果
    show_scores();

    // 4. 保存分数到文件中
    save_records();
    cout << "本届比赛完毕！" << endl;
    cout << "按 Enter 键继续..." << endl;
    cin.get();
    system("clear");
}

// 开始淘汰赛
void SpeechManager::start_knock_out()
{
    cout << "---------- 第 " << this->m_round_count << " 轮比赛正式开始！----------" << endl;

    // 准备临时容器，存放小组成绩(key: 具体得分, value: 选手编号)
    multimap<double, int, greater<double>> group_score;

    // 统计人员个数，每 6 个人一组
    int player_count = 0;

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
        player_count++;

        // 评委打分 deque 容器
        deque<double> deq;
        for (int i = 0; i < 10; i++)
        {
            // 产生一个 [60,100] 的随机数
            double _score = (rand() % 401 + 600) / 10.0f;
            // 设置每个小数显示2位小数
            // --------------- 调试信息 ------------------
            // cout << "得分：" << fixed << setprecision(2) << _score << " ";
            // cout << "得分：" << _score << " ";

            deq.push_back(_score);
        }
        // --------------- 调试信息 ------------------
        // cout << endl;
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
        // --------------- 调试信息 ------------------
        // cout << "-------------" << avg << "-----------" << endl;

        // 输出每个人的平均分
        // --------------- 调试信息 ------------------
        // cout << "编号: " << *it << ", 姓名: " << this->m_speakers[*it].m_name << ", 平均分: " << avg << endl << endl;

        // 将平均分放入到 map 容器里
        this->m_speakers[*it].m_scores[this->m_round_count - 1] = avg;

        // 将打分数据放入到临时小组容器中
        group_score.insert(make_pair(avg, *it));

        // 每 6 个人取前三名
        if (player_count % 6 == 0)
        {
            cout << endl;
            cout << "第 " << (player_count / 6) << " 小组比赛名次：" << endl;
            for (multimap<double, int, greater<double>>::iterator mit = group_score.begin(); mit != group_score.end(); ++mit)
            {
                cout << "编号:" << mit->second << ", 姓名: " << this->m_speakers[mit->second].m_name << ", 成绩: " << this->m_speakers[mit->second].m_scores[this->m_round_count - 1] << endl;
            }

            // 取走前三名
            int top3_count = 0;
            for (multimap<double, int, greater<double>>::iterator mit = group_score.begin(); mit != group_score.end() && top3_count < 3; ++mit, top3_count++)
            {
                // 如果是第一轮比赛
                if (this->m_round_count == 1)
                {
                    // 如果是第一轮比赛结束，则将前三名放入到 v2 容器中
                    v2.push_back(mit->second);
                }
                else
                {
                    // 如果是第二轮比赛结束，则将前三名放入到 v_victory 容器中
                    v_victory.push_back(mit->second);
                }
            }

            // 临时容器清空
            group_score.clear();
            // cout << "==========================================" << endl;
        }
    }

    cout << "------------第 " << this->m_round_count << " 轮比赛完毕！-----------" << endl;
}

// 显示得分
void SpeechManager::show_scores()
{
    cout << "第 " << this->m_round_count << " 轮晋级的选手信息如下：" << endl;
    vector<int> v;
    // 判断是第几轮，如果是第一轮，要显示的是 v2 中的信息，如果是第二轮结束，要显示的是 v_victory 中的信息
    if (this->m_round_count == 1)
    {
        v = v2;
    }
    else
    {
        v = v_victory;
    }
    // cout << "::::::::::::::::::" << v.size() << ":::::::::::::::::" << endl;

    // 遍历显示
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << "编号: " << *it << ", 姓名: " << this->m_speakers[*it].m_name << ", 得分: "
             << this->m_speakers[*it].m_scores[this->m_round_count - 1] << endl;
    }
    cout << endl;
    cout << "按 Enter 键继续..." << endl;
    // 不是在 cin << bianliang; 之后使用 cin.get() 所以不需要用 cin.ignore();
    // cin.ignore();
    cin.get();
    system("clear");

    // 重新显示菜单
    this->show_menu();
}

// 将比赛数据写入文件
void SpeechManager::save_records()
{
    ofstream ofs;
    // ios::app, 表示 append
    ofs.open("lecture.csv", ios::out | ios::app);
    // 将每个人的数据写入到文件中
    for (vector<int>::iterator it = v_victory.begin(); it != v_victory.end(); ++it)
    {
        // m_scores[1], 表示第二轮成绩
        ofs << *it << "," << this->m_speakers[*it].m_scores[1] << ",";
    }
    ofs << endl;

    // 关闭文件
    ofs.close();
    cout << "记录已经保存" << endl;
    this->is_file_empty = false;
}

// 加载记录分数(从文件中读取)
void SpeechManager::load_records()
{
    this->m_records.clear();
    // 1. 创建文件读取流
    ifstream ifs("lecture.csv", ios::in);

    // 2. 检查文件是否打开成功
    if (!ifs.is_open())
    {
        // 如果文件打开失败，则认为文件不存在！
        // 如果文件不存在，则设置 is_file_empty = true
        this->is_file_empty = true;
        // cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }

    // 判断文件是否为空
    char ch;
    ifs >> ch; // 先读取一个字符
    // 如果读取一个字符后，立即遇到文件尾，则表示文件为空
    if (ifs.eof())
    {
        // cout << "文件为空！" << endl;
        this->is_file_empty = true;
        ifs.close();
        return;
    }

    // 如果文件存在 且 文件不为空
    this->is_file_empty = false;
    // 将测试读取的单个字符放回去
    ifs.putback(ch);

    string line_data; // 保存从文件中读取的每行数据
    int idx = 0;      // 记录届数, 从 0 开始

    // 从文件中逐行读取数据
    while (ifs >> line_data)
    {
        // 输出刚才读取到的数据（调试用)
        // cout << line_data << endl;

        // 创建向量, 存放解析后的字段数据
        vector<string> v;
        int pos = -1;  // 记录逗号的位置
        int start = 0; // 当前解析的起始位置

        // 解析逗号分隔的数据
        while (true)
        {
            // 从 start 位置开始找 , 出现的索引
            pos = line_data.find(",", start);
            if (pos == -1)
            {
                break; // 表示没有找到 ,
            }
            // 如果找到了 "," 则根据 "," 进行分割
            string temp = line_data.substr(start, pos - start);
            v.push_back(temp); // 将解析到的字段数据添加到 v 向量中
            // cout << temp << endl;
            start = pos + 1;
        }

        // 将解析出的数据存储历史记录映射表
        // key: 届数索引, value: 该届比赛前三名选手的编号和得分
        this->m_records.insert(make_pair(idx, v));
        idx++; // 届数递增
    }
    ifs.close(); // 关闭文件流

    // // 调试信息
    // // 遍历 map 容器
    // for (map<int, vector<string>>::iterator it = m_records.begin(); it != m_records.end(); ++it)
    // {
    //     cout << "冠军编号：" << it->first << ", 分数: " << it->second[0] << endl;
    // }
}

// 查看记录功能
void SpeechManager::show_records()
{
    // 如果程序没有退出, 只在构造函数的时候 load_records() 一次，此处没有执行 load_records() ，所以查不到数据
    this->load_records();

    // 判断如果文件不存在的话提示
    if (this->is_file_empty)
    {
        cout << "数据文件不存在，或数据文件为空！" << endl;
    }

    // cout << "-----" << this->m_records.size() << "-----" << endl;
    // 遍历每届比赛
    for (int i = 0; i < this->m_records.size(); i++)
    {
        cout << "第 " << (i + 1) << " 届" << "冠军🏆编号: " << this->m_records[i][0] << ", 得分: " << this->m_records[i][1]
             << "; 亚军🥈编号: " << this->m_records[i][2] << ", 得分: " << this->m_records[i][3]
             << "; 季军🥉编号: " << this->m_records[i][4] << ", 得分: " << this->m_records[i][5] << endl;
    }
    cout << "按 Enter 键继续..." << endl;
    cin.get();
    system("clear");
}

// 清空记录
void SpeechManager::clear_records()
{
    cout << "确认要清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int selected = 0;
    cin >> selected;
    if (selected == 1)
    {
        // 清空: 读取 lecture.csv 文件并且清空该文件；同时清空内存数据
        ofstream ofs("lecture.csv", ios::trunc);
        ofs.close();
        // 重新初始化程序
        this->init_data();
        this->createSpeakers();
        this->load_records();
        cout << "清空数据成功！" << endl;
    }
    cin.ignore();
    cout << "按 Enter 键继续..." << endl;
    cin.get();
    system("clear");
}