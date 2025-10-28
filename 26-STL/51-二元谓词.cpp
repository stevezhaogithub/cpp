#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class MyCompare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void print_vector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 二元谓词
void test01()
{
    vector<int> v;
    v.push_back(40);
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);

    // 通过 sort() 直接排序
    sort(v.begin(), v.end()); // 默认是升序排序

    // 遍历输出
    print_vector(v);

    cout << "降序排序后：" << endl;
    // 通过仿函数，修改排序规则————降序排序
    sort(v.begin(), v.end(), MyCompare());
    print_vector(v);
}

int main()
{
    test01();
    return 0;
}