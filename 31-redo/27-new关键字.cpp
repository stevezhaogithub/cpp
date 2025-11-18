
/**
 * 
 * 1. 释放普通堆区内存
 * delete p
 * 
 * 2. 释放数组内存
 * delete[] p
 * 
 */
#include <iostream>

// 1. new 的基本语法
int *func()
{
    // new 返回的是该数据类型的指针
    int *data = new int(10);
    // 释放以后, 再读取 data 中的数据，显示为 0
    delete data;
    return data;
}
void test1()
{
    int *p = func();
    std::cout << *p << std::endl;
}

// 2. 在堆区利用 new 关键字开辟数组
void test2()
{
    // 在堆区创建长度为10的 int 型数组
    int *ptr1 = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        ptr1[i] = i + 100;
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << ptr1[i] << std::endl;
    }

    // 释放数组内存
    delete[] ptr1;
}
int main()
{
    // test1();
    test2();

    return 0;
}