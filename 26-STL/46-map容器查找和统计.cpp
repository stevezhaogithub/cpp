#include <iostream>
#include <map>
using namespace std;

// map 容器的查找和统计
void test01()
{
    map<int, int> mp;
    mp.insert(make_pair(1, 100));
    mp.insert(make_pair(2, 200));
    mp.insert(make_pair(2, 200));
    mp.insert(make_pair(2, 200));
    mp.insert(make_pair(2, 200));
    mp.insert(make_pair(2, 200));
    mp.insert(make_pair(2, 200));
    mp.insert(make_pair(3, 300));
    mp.insert(make_pair(4, 400));
    mp.insert(make_pair(5, 500));

    // 查找
    map<int, int>::iterator pos = mp.find(3000);
    if (pos != mp.end())
    {
        cout << "查到了元素: key = " << pos->first << ", value = " << pos->second << endl;
    }
    else
    {
        cout << "未找到元素！" << endl;
    }

    // 统计
    int _count = mp.count(2); // 因为不允许有重复的 key，所以 结果要么是1要么是0
    cout << "_count = " << _count << endl;
    // multimap 的 count(key) 可能是大于1的结果
}

int main()
{
    test01();
    return 0;
}
