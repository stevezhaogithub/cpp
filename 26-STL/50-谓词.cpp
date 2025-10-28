#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 一元谓词
// 大于 5 的谓词
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 50;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back((i + 1));
    }

    // 查找容器中是否有大于 5 的数字: find_if()
    // GreaterFive() 表示：匿名的函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "未找到大于 5 的数字" << endl;
    }
    else
    {
        cout << "找到了大于 5 的数字（如下）：" << endl;
        while (it != v.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
}

int main()
{
    test01();
    return 0;
}

/*
    谓词
    1. 返回值为 bool 类型的仿函数
    2. 有一个形参 ———— 一元谓词
    3. 有两个形参 ———— 二元谓词

*/