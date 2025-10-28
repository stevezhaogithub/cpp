#include <iostream>
#include <string>
using namespace std;

// pair 对组，利用对组可以返回两个数据
void test01()
{
    // 两种创建方式
    // 1.
    // pair<type, type> p(value1, value2);

    // 2.
    // pair<type, type> p = make_pair(value1, value2);

    pair<string, int> p("tom", 20);
    cout << "姓名：" << p.first << " - " << p.second << endl;

    pair<string, int> p2 = make_pair("jerry", 30);
    cout << "姓名：" << p2.first << " - " << p2.second << endl;
}
int main()
{
    test01();
    return 0;
}