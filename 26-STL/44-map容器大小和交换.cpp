#include <iostream>
#include <map>
using namespace std;

void print_map(map<int, int> &mp)
{
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << "k = " << it->first << ", v = " << it->second << ";" << endl;
    }
}

void test01()
{
    map<int, int> mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    // mp.clear();

    // 判断 map 是否为空
    if (mp.empty())
    {
        cout << "map is empty." << endl;
    }
    else
    {
        cout << "map is not empty." << endl;
        cout << "the size of map is: " << mp.size() << endl;
    }
}

// 交换
void test02()
{
    map<int, int> mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));

    map<int, int> mp2;
    mp2.insert(pair<int, int>(9, 900));
    mp2.insert(pair<int, int>(8, 800));
    mp2.insert(pair<int, int>(7, 700));
    mp2.insert(pair<int, int>(6, 600));
    mp2.insert(pair<int, int>(5, 500));

    // 交换前
    cout << "交换前：" << endl;
    cout << "mp:" << endl;
    print_map(mp);
    cout << "mp2:" << endl;
    print_map(mp2);
    // 交换
    mp.swap(mp2);
    cout << "交换后：" << endl;
    cout << "mp:" << endl;
    print_map(mp);
    cout << "mp2:" << endl;
    print_map(mp2);

}

int main()
{
    // test01();
    test02();
    return 0;
}