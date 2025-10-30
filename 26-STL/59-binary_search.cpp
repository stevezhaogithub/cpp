/*
    查找指定的元素是否存在.
    1. bool binary_search(begin, end, value);
    2. 只能查找有序列表（二分查找法）
    3.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// binary_search
void test01()
{
    // bool binary_search()
    vector<int> v;
    for (int i = 0; i < 50; i++)
    {
        v.push_back(i);
    }
    // 查找容器中是否有 9
    bool ret = binary_search(v.begin(), v.end(), 999);
    cout << (ret ? "yes" : "no") << endl;
}
int main()
{
    test01();
    return 0;
}