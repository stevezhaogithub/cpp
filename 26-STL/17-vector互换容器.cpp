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

// 通过 swap 交换两个 vector，指针的指向变了
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i + 1);
    }
    print_vector(v1);

    vector<int> v2;
    for (int i = 5; i > 0; i--)
    {
        v2.push_back(i + 1);
    }
    print_vector(v2);

    cout << "交换v1 和 v2" << endl;
    v1.swap(v2);

    cout << "v1: " << endl;
    print_vector(v1);
    cout << "v2: " << endl;
    print_vector(v2);
}

void test02()
{
    vector<int> v1;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
    }
    cout << "容量：" << v1.capacity() << endl;
    cout << "大小：" << v1.size() << endl;

    v1.resize(3);

    cout << "执行： v1.resize(3); 之后：" << endl;
    cout << "容量：" << v1.capacity() << endl;
    cout << "大小：" << v1.size() << endl;

    // 收缩空间
    vector<int>(v1).swap(v1);
    cout << "收缩空间后：" << endl;
    cout << "容量：" << v1.capacity() << endl;
    cout << "大小：" << v1.size() << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}