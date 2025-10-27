/*
    set容器:
    1. 所有元素都会在插入时自动被排序
    2. set容器 和 multiset 容器底层是通过二叉树实现的
    3. set容器不允许容器中有重复元素
    4. multiset允许容器中有重复的元素
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;

void print_set(set<int> &S)
{
    for (set<int>::iterator it = S.begin(); it != S.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// set 容器的构造和赋值
void test01()
{
    set<int> s1;
    // set 容器在插入数据的时候只有 insert
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(4);
    s1.insert(3);
    s1.insert(1);
    s1.insert(1);
    s1.insert(1);
    s1.insert(1);

    // set 中无重复元素，会自动排序
    print_set(s1);

    // 拷贝构造
    set<int> s2(s1);
    print_set(s2);

    // 赋值构造
    set<int> s3 = s2;
    print_set(s3);
}
int main()
{
    test01();
    return 0;
}