#include <iostream>
#include <vector>
using namespace std;

// 统计 vector 重新分配了多少次内存
void test01()
{
    vector<int> v1;
    int num = 0;
    int *ptr_vector = NULL;

    for (int i = 0; i < 1000000; i++)
    {
        v1.push_back(i);
        if (ptr_vector != &v1[0])
        {
            ptr_vector = &v1[0];
            num++;
        }
    }

    // 10W 次，进行了 18次内存分配
    // 100W 次，进行了 21 次内存分配
    cout << "重新分配了：" << num << " 次内存。" << endl;
}

// 通过 reserve() 提前预留内存
void test02()
{
    vector<int> v1;
    int num = 0;
    int *ptr_vector = NULL;

    // 利用 reserve() 预留1000000个空间
    v1.reserve(1000000);

    for (int i = 0; i < 1000000; i++)
    {
        v1.push_back(i);
        if (ptr_vector != &v1[0])
        {
            ptr_vector = &v1[0];
            num++;
        }
    }

    // 100W 次，进行了 1 次内存分配
    cout << "重新分配了：" << num << " 次内存。" << endl; 
}

int main()
{
    // test01();
    test02();
    return 0;
}