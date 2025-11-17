#include <iostream>
using namespace std;
int main()
{

    // 1. 定义指针
    int a = 10;
    int *p = &a;
    cout << p << endl;
    cout << *p << endl;
    cout << "-----------------------------" << endl;

    // 2. 指针所占用的空间
    cout << "int * 类型的指针占用空间: " << sizeof(p) << endl;
    cout << "double * 类型的指针占用空间: " << sizeof(double *) << endl;
    cout << "char * 类型的指针占用空间: " << sizeof(char *) << endl;
    cout << "-----------------------------" << endl;

    // 3. 空指针
    cout << "NULL = " << NULL << endl;
    int *ptr = NULL;
    // 空指针是不可以访问的 (0 ~ 255之间的内存编号是系统占用的, 因此不可以访问)
    // *ptr = 100;                        // [1]    42086 segmentation fault
    // cout << "*ptr = " << *ptr << endl; // [1]    41742 segmentation fault

    // 4. 野指针
    cout << "-----------野指针------------------" << endl;
    // 野指针
    float *ptr_f = (float *)0x1100;
    // cout << *ptr_f << endl; // [1]    44208 segmentation fault

    // 5. 常量指针：指针本身是常量 const pointer, 指针的指向不能改变
    int int_value = 100;
    int *const ptr_int = &int_value; // 整型常量指针

    // 6. 指针常量：指向常量的指针
    const int cvalue = 1000;
    const int *ptr_const_value = &cvalue;

    return 0;
}

/**
 *
 * 一、空指针
 * 定义: 指针变量指向内存中编号为 0 的空间
 * 用途:
 * 1. 用于给指针变量初始化
 * 2. 空指针是不可以访问的
 * 注意: 空指针指向的内存是不可以访问的
 * int *p = NULL;
 *
 * 二、野指针
 * 定义: 指针变量指向非法的内存空间
 *
 *
 *
 * 三、指针的定义
 * int a = 10;
 * int *p = &a;
 * cout << *p << endl;
 *
 *
 * 四、指针所占用的空间
 * 1. 在 32 位 OS 下任何类型的指针占用空间都是 4 个字节
 * 2. 在 64 位 OS 下任何类型的指针占用空间都是 8 个字节
 *
 *
 *
 *
 */