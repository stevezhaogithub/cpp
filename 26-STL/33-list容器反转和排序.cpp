#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// list 容器反转 和 排序
void test01()
{
    list<int> L1;
    L1.push_back(20);
    L1.push_back(2);
    L1.push_back(200);
    L1.push_back(30);
    L1.push_back(10);

    cout << "反转前：" << endl;
    print_list(L1);
    cout << "反转后：" << endl;
    L1.reverse();
    print_list(L1);
}

// 自定义排序
bool my_compare(int a, int b)
{
    // 降序: 让第一个数大于第二个数
    return a > b;
}

void test02()
{
    list<int> L1;
    L1.push_back(20);
    L1.push_back(2);
    L1.push_back(200);
    L1.push_back(30);
    L1.push_back(10);

    cout << "排序前：" << endl;
    print_list(L1);
    // 默认排序规则是从小到大（升序）
    L1.sort();

    // 降序排序
    L1.sort(my_compare);
    cout << "排序后：" << endl;
    print_list(L1);

    // 所有不支持随机迭代器的容器，都不能用 "标准算法"
    // sort(L1.begin(), L1.end()); // 不支持
    // 不支持随机迭代器的容器，内部都会提供对应的一些算法
}
int main()
{
    // test01();
    test02();
    return 0;
}