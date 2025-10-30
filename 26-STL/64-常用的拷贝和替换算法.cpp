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

// 一元谓词
class GT30
{
public:
    bool operator()(int d)
    {
        return d >= 30;
    }
};

// 按条件替换: replace_if
void test03()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);

    // 输出
    for_each(v.begin(), v.end(), fn);
    cout << endl;

    // 将 >= 30 的替换成 3000
    replace_if(v.begin(), v.end(), GT30(), 3000);

    cout << "替换后：" << endl;
    // 输出
    for_each(v.begin(), v.end(), fn);
    cout << endl;
}

void print_vectorInt(const vector<int> &v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// swap()
void test04()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    cout << "v1:" << endl;
    print_vectorInt(v);
    cout << "v2:" << endl;
    print_vectorInt(v2);

    v.swap(v2);

    cout << "交换后：" << endl;
    cout << "v1:" << endl;
    print_vectorInt(v);
    cout << "v2:" << endl;
    print_vectorInt(v2);
}
int main()
{
    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}