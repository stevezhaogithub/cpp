#include <iostream>
#include <map>
using namespace std;

void print_map(map<int, int> &mp)
{
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << "key = " << it->first << ", value = " << it->second << endl;
    }
}

void test01()
{
    map<int, int> mp;
    // 第一种插入
    mp.insert(pair<int, int>(1, 10));
    // 第二种插入
    mp.insert(make_pair(2, 20));
    // 第三种插入
    mp.insert(map<int, int>::value_type(3, 30));
    // 第四种：不建议使用这种方式插入，但是可以使用这种方式遍历
    mp[4] = 40;

    print_map(mp);

    // 没有 key = 5, 的键值对。但是这里确实能输出是 0
    cout << mp[5] << endl;
}
int main()
{
    test01();
    return 0;
}