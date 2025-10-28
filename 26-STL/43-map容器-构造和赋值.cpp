#include <iostream>
#include <map>
using namespace std;

void print_map(map<int, int> &mp)
{
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << "key = " << it->first << ", value = " << it->second << endl;
    }
}

void test01()
{
    // 创建 map 容器
    map<int, int> mp;
    // 插入后，会自动按照 key 进行排序
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(4, 40));
    print_map(mp);

    cout << " ------------------------- " << endl;

    // 拷贝构造
    map<int, int> mp2(mp);
    print_map(mp2);

    // 赋值
    cout << " ------------------------- " << endl;
    map<int, int> mp3 = mp;
    print_map(mp2);
}

int main()
{
    test01();
    return 0;
}

/*
    map 与 multimap 容器
    1. map 容器中所有元素都是 pair
    2. pair 中第一个元素是 key, 第二个元素是 value
    3. 所有元素都会根据元素的键值自动排序
    4. 本质：
        - map 和 multimap 属于关联容器，底层结构是用二叉树实现
    5. 可以根据 key 值快速找到 value
    6.
        - map 不允许容器中有重复的 key
        - multimap 允许容器中有重复的 key 值元素


*/
