/*
    Vector 可以理解为 数组
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_fn(int _val)
{
    cout << _val << " ";
}

// vector 容器

void test01()
{
    vector<int> nums;
    // 尾插法
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.push_back(40);
    nums.push_back(50);

    // // --------------- 遍历方法一、 ---------------

    // // 通过迭代器访问容器中的数据
    // vector<int>::iterator it_begin = nums.begin(); // 起始迭代器，指向容器中的第一个元素
    // vector<int>::iterator it_end = nums.end();     // 结束迭代器，指向容器中最后一个元素的下一个位置

    // // 第一种遍历
    // while (it_begin != it_end)
    // {
    //     cout << *it_begin << endl;
    //     it_begin++;
    // }

    // //  ---------------  遍历方法二、 ---------------
    // for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // --------------- 遍历方法三、 ---------------
    for_each(nums.begin(), nums.end(), print_fn);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}