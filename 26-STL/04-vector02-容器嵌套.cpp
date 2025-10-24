#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_fn(vector<int> _data)
{
    for (vector<int>::iterator it = _data.begin(); it != _data.end(); ++it)
    {
        cout << " - " << *it << " - ";
    }
    cout << endl;
}

void test01()
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 遍历输出
    for_each(v.begin(), v.end(), print_fn);
}
int main()
{
    test01();
    return 0;
}