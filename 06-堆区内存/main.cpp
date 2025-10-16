//
//  main.cpp
//  06-堆区内存
//
//  Created by steve xiaohu zhao on 2025/9/29.
//

#include <iostream>
#include <string>
using namespace std;

int *func() {
    // 在堆上开辟内存, new int(10) 返回的是一个 int 类型指针
    int *a = new int(10);
    return a;
}

int *func_new() {
    // 在堆区创建整型数据, new xxx(); 会返回一个 xxx 类型的指针
    int *p = new int(10);
    return p;
}

// 创建一个长度为 10 的 int 类型数组
int *func_new_array() {
    int *nums = new int[10];
    for (int i = 0; i < 10; i++) {
        nums[i] = (i + 1) * 3;
    }
    return nums;
}

int main(int argc, const char *argv[]) {

    //    // 在堆区开辟内存
    //    int *p = func();
    //    cout << *p << endl;
    //    cout << *p << endl;
    //    cout << *p << endl;
    //    cout << *p << endl;

    // new 关键字使用
    // 1. new 开辟
    int *ptr = func_new();
    cout << "*ptr = " << *ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    // 2. delete 释放内存
    // 堆区的内存，由管理员开辟，并释放
    delete ptr;
    cout << "--------delete-------" << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "ptr = " << ptr << endl;

    //
    int *array = func_new_array();
    for (int i = 0; i < 10; i++) {
        cout << array[i] << endl;
    }
    
    delete[] array;
    cout << "--------delete[]-------" << endl;
    for (int i = 0; i < 10; i++) {
        cout << array[i] << endl;
    }
    return 0;
}
