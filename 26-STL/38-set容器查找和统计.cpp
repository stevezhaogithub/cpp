#include <iostream>
#include <set>
using namespace std;

// 查找和统计：find() and count()
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(1);
    s1.insert(1);
    s1.insert(1);
    s1.insert(1);
    s1.insert(1);
    s1.insert(90);
    s1.insert(110);
    s1.insert(9);

    // 查找, 如果找到了对应的数据，则返回迭代器，否则返回set.end()
    set<int>::iterator it = s1.find(1);
    if (it != s1.end())
    {
        cout << "找到了对应的数据！" << endl;
        cout << *it << endl;
    }
    else
    {
        cout << "未找到对应的数据！" << endl;
    }

    // 统计 count(key): 统计 key 的元素个数
    // 对于 set 来说， count() 返回不是 0 就是 1，因为 set 中不允许出现重复元素
    cout << "s1.count(1) = " << s1.count(1) << endl;
}

int main()
{
    test01();
    return 0;
}