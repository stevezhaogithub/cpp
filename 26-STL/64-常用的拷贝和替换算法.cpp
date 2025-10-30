/*
    copy
    replace
    replace_if
    swap
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fn(int d)
{
    cout << d << " ";
}

// copy 算法
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(), v.end(), v2.begin());

    for_each(v2.begin(), v2.end(), fn);
    cout << endl;
}

// 仿函数
class MyPrint
{
public:
    void operator()(int d)
    {
        cout << d << " ";
    }
};

// replace 替换算法
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    //  将 3 替换成 333
    replace(v.begin(), v.end(), 3, 333);
    cout << "替换后：" << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}