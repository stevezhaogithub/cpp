#include <iostream>
#include <list>
using namespace std;

// list 容器数据存取
void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // 无法通过 [] 和 at() 访问。链表不能通过索引访问，不是线性空间存储,
    // 所以 list 的迭代器不支持随机访问
    // L1[0]、L1.at()

    // 访问第一个元素 和 最后一个元素
    cout << "第一个元素：" << L1.front() << endl;
    cout << "最后一个元素：" << L1.back() << endl;

    // 验证迭代器不支持随机访问
    list<int>::iterator it = L1.begin();
    it++; // 对的
    // it = it + 1; // 错误. error: invalid operands to binary expression。如果可以 it = it + 1, 那么就可以 it = it + 2;
    it--; // 对的

    // 支持 it++; 和 it--; 表示支持双向
    // 不支持 it = it + 1; 表示不支持随机访问
}
int main()
{
    test01();
    return 0;
}