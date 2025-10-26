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

// 容量和大小
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        // 翻倍的增长
        cout << "capacity = " << v1.capacity() << endl;
        cout << "size = " << v1.size() << endl;
        v1.push_back((i + 1));
    }

    // 输出
    print_vector(v1);

    if (v1.empty())
    {
        cout << "v1 is empty." << endl;
    }
    else
    {
        cout << "v1 is not empty." << endl;
    }

    cout << "capacity = " << v1.capacity() << endl;

    // 重新指定大小
    // v1.resize(20); // 重新指定大小，并且用 0 来填充
    v1.resize(20, 999); // 重新指定大小并且用 999 来填充
    print_vector(v1);

    v1.resize(2); // 超出 2 的部分会删除
    print_vector(v1);
}

int main()
{
    test01();
    return 0;
}