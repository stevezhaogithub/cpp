#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &_v)
{
    for (vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;

    // 向 v1 中插入数据
    for (int i = 0; i < 10; i++)
    {
        v1.push_back((i + 1) * 2);
    }

    // 输出 v1 中的所有数据
    print_vector(v1);

    cout << "---------------------------" << endl;
    // 1. 直接赋值
    vector<int> v2;
    v2 = v1;
    print_vector(v2);

    cout << "---------------------------" << endl;
    // 2. 通过 assign() 方式赋值
    vector<int> v3;
    // 注意：end() 表示的是最后一个元素后面的位置
    // assign(begin, end) 是 左闭右开 [begin, end) , begin 指向的位置是可以取到的， end 指向的位置是取不到的
    v3.assign(v2.begin(), v2.end());
    print_vector(v3);

    cout << "---------------------------" << endl;
    // 3. 10 个 888
    vector<int> v4;
    v4.assign(10, 888);
    print_vector(v4);
}

int main()
{
    test01();
    return 0;
}