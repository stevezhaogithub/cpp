#include <iostream>
#include <map>
using namespace std;

// 自己写仿函数，改变排序规则
class MyCompare
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

void test01()
{
    // 改变排序规则
    map<int, int, MyCompare> mp;
    mp.insert(make_pair(1, 10));
    mp.insert(make_pair(2, 20));
    mp.insert(make_pair(7, 70));
    mp.insert(make_pair(3, 30));
    mp.insert(make_pair(4, 40));
    mp.insert(make_pair(5, 50));
    mp.insert(make_pair(6, 60));

    // 遍历输出, 主意：如果改变了默认的排序规则，则遍历的时候也需要指定 MyCompare
    for (map<int, int, MyCompare>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << "key = " << it->first << ", value = " << it->second << endl;
    }
}
int main()
{
    test01();
    return 0;
}