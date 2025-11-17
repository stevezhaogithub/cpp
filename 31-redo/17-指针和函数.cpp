#include <iostream>

void swap(int *a, int *b);

int main()
{
    int x = 10, y = 20;
    swap(&x, &y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 一、函数参数传递时的指针
 *
 *
 */