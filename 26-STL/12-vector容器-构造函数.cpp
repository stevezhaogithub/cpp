#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


void test01()
{
    // 1. 默认构造函数（无参构造函数）
    vector<int> v1;
    // 插入数据
    for (int i = 0; i < 5; i++)
    {
        v1.push_back((i + 1) * 2);
    }

    // // 输出数据(OK的)
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     cout << v1[i] << endl;
    // }

    // 输出
    print_vector(v1);

    cout << "-------------------- " << endl;

    // 2. 通过区间构造
    vector<int> v2(v1.begin(), v1.end());
    // 输出
    print_vector(v2);

    cout << "-------------------- " << endl;

    // 3. 通过 n 个 element 的方式进行构造
    // v3 中包含 10 个 999
    vector<int> v3(10, 999);
    print_vector(v3);

    cout << "-------------------- " << endl;
    // 4. 拷贝构造
    vector<int> v4(v3);
    print_vector(v4);
}

int main()
{
    test01();

    return 0;
}

/*
    vector:
    0. 和数组非常相似
    1. 单端数组(vector的 front 是封闭的，只能通过 tail 尾部进行插入：push_back() 和删除 pop())
    2. vector 可以动态扩展（不是在原有数组后扩展，而是找更大的空间将元数据拷贝到新的空间，并释放原空间）


    构造函数：
    1. 无参构造函数： vector<T> v;
    2. vector<T> v(v.begin(), v.end())
    3. vector<T> v(n, element)
    4. vector(const vector &_vector)

*/