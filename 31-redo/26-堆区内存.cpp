#include <iostream>

int *func()
{
    // new 关键字开辟内存
    int *a = new int(10);
    return a;
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        // 因为 func() 返回的是堆区的内存, 所以该内存一直没有被释放，所以可以一直访问
        int *p = func();
        std::cout << *p << std::endl;
        // 释放每次调用 func() 返回的内存
        delete p;
    }

    return 0;
}