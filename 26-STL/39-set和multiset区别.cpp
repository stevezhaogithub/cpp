#include <iostream>
#include <set>
using namespace std;
void test01()
{

    set<int> s1;
    pair<set<int>::iterator, bool> ret = s1.insert(10);
    if (ret.second)
    {
        cout << "第一次插入成功了！" << endl;
    }
    else
    {
        cout << "第一次插入失败！" << endl;
    }

    // 第二次插入相同的数据
    pair<set<int>::iterator, bool> ret1 = s1.insert(10);
    if (ret1.second)
    {
        cout << "第一次插入成功了！" << endl;
    }
    else
    {
        cout << "第一次插入失败！" << endl;
    }

    multiset<int> ms1;
    ms1.insert(100);
    ms1.insert(100);
    ms1.insert(100);
    ms1.insert(100);
    for (multiset<int>::iterator it = ms1.begin(); it != ms1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    test01();
    return 0;
}