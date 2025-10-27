#include <iostream>
#include <set>
using namespace std;

void print_set(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    set<int> s1;
    // 插入
    s1.insert(10);
    s1.insert(100);
    s1.insert(9);
    s1.insert(8);
    s1.insert(2);
    // 输出
    print_set(s1);

    // 删除
    // 把排序后的第一个元素给删除了
    s1.erase(s1.begin());
    print_set(s1);

    // 删除的重载版本
    s1.erase(100); // 把元素值为100的给删除了
    print_set(s1);

    // 清空
    // s1.erase(s1.begin(), s1.end());
    s1.clear();
    print_set(s1);
}
int main()
{
    test01();
    return 0;
}
