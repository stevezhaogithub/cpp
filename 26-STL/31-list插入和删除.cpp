#include <iostream>
#include <list>
using namespace std;

// 参数这里如果加 const 关键字,那么要用 list<int>::const_iterator 迭代器
void print_list(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    list<int> L1;
    // 尾插
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);

    // 头插
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);

    print_list(L1);

    // 尾删
    L1.pop_back();
    print_list(L1);

    // 头删
    L1.pop_front();
    print_list(L1);

    // insert 插入
    L1.insert(L1.begin(), 999);
    print_list(L1);

    list<int>::iterator _iterator = L1.begin();
    // _iterator 向后偏移 3 个元素的位置
    advance(_iterator, 3);
    L1.insert(_iterator, 999999);
    print_list(L1);

    // 删除
    L1.erase(++L1.begin());
    print_list(L1);

    // remove() 根据值进行删除
    L1.push_back(888);
    L1.push_back(888);
    L1.push_back(888);
    L1.push_back(888);
    print_list(L1);

    // 删除所有值等于888的元素
    L1.remove(888);
    print_list(L1);

    // 清空 list
    L1.clear();
    print_list(L1);
}
int main()
{
    test01();
    return 0;
}