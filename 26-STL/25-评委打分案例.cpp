#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// 选手类
class Player
{
public:
    Player(string _name, double _score)
    {
        this->m_name = _name;
        this->m_score = _score;
    }
    string m_name;  // 姓名
    double m_score; // 平均分
};

// 遍历输出 vector 容器中的内容
void print_players(vector<Player> &v)
{
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->m_name << ", 最终得分：" << it->m_score << endl;
    }
}

void create_players(vector<Player> &_v)
{
    string name_seed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string _name = "Player-";
        _name += name_seed[i];
        int _score = 0;

        // 创建选手
        Player player(_name, _score);
        _v.push_back(player);
    }
}

void set_score(vector<Player> &_v)
{
    for (vector<Player>::iterator it = _v.begin(); it != _v.end(); it++)
    {
        // 将评委的分数放到 deque 容器中
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            // 产生一个 60 ~ 100 的随机数
            int _score = (rand() % 41 + 60);
            d.push_back(_score);
            // cout << _score << " ";
        }
        // cout << endl;
        //  排序
        sort(d.begin(), d.end());
        // 去掉最高分和对低分
        d.pop_front(); // 去掉最高分
        d.pop_back();  // 去掉最低分
        // 计算平均分
        double total = 0.0;
        double average = 0;
        for (deque<int>::const_iterator dit = d.begin(); dit != d.end();
             dit++)
        {
            total += *dit;
        }
        average = total / d.size();
        it->m_score = average;
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 1. 创建 5 名选手
    vector<Player> v;
    create_players(v);

    // 测试
    //    for (int i = 0; i < v.size(); i++) {
    //        cout << v[i].m_name << " - " << v[i].m_score << endl;
    //    }

    // 2. 给 5 名选手打分
    set_score(v);

    // 测试
    //    for (int i = 0; i < v.size(); i++) {
    //        cout << v[i].m_name << " - " << v[i].m_score << endl;
    //    }

    // 3. 显示最后得分
    print_players(v);
    return 0;
}

/*
    1. 有 5 名选手：ABCDE
    2. 有 10 位评委，分别对每一名选手打分，去除最高分、最低分，取平均分

 */
