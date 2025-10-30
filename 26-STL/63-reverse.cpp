#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void fn(int d)
{
    cout << d << " ";
}

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << "反转前：" << endl;
    for_each(v.begin(), v.end(), fn);
    cout << endl;

    // 反转
    reverse(v.begin(), v.end());
    cout << "反转后：" << endl;
    for_each(v.begin(), v.end(), fn);
    cout << endl;
}
int main()
{
    test01();

    return 0;
}