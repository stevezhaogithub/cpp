
/*
    常用的排序算法：
    1. sort(), 排序
    2. random_shuffle() , 洗牌，指定范围内的元素随机调整次序
    3. merge, 容器元素合并，并存储到另一容器中
    4. reverse(), 反转指定范围的元素

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <ctime>
#include <random>
using namespace std;

// 用于 for_each() 输出
void fn(int d)
{
    cout << d << " ";
}

// 遍历输出 vector
void print_vector(const vector<int> &v)
{
    for_each(v.begin(), v.end(), fn);
    cout << endl;
}

// sort() 算法
void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);

    // 输出
    print_vector(v);

    // 排序
    cout << "排序后：" << endl;
    sort(v.begin(), v.end());
    print_vector(v);

    // 降序排序
    cout << "降序排序后：" << endl;
    // 使用内置函数对象 greater 实现降序排序
    sort(v.begin(), v.end(), greater<int>());
    print_vector(v);
}

// random_shuffle() 算法
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // shuffle 前
    cout << "shuffle 前:" << endl;
    print_vector(v);

    // random_shuffle() 已过时，建议使用 shuffle()
    // random_shuffle(v.begin(), v.end());
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);
    cout << "shuffle 后:" << endl;
    print_vector(v);
}

// merge 算法
void test03()
{
    srand((unsigned int)time(NULL));
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back((i + 1));
    }

    // 目标容器
    vector<int> v_target;
    // 为 v_target 分配大小
    v_target.resize(v1.size() + v2.size());
    // 合并后还是一个有序序列
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target.begin());

    // 遍历输出 v_target
    for_each(v_target.begin(), v_target.end(), fn);
    cout << endl;
}

int main()
{

    // test01();
    // test02();
    test03();
    return 0;
}