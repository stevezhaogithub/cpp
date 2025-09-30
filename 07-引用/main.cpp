//
//  main.cpp
//  07-引用
//
//  Created by steve xiaohu zhao on 2025/9/30.
//

#include <iostream>
#include <string>
using namespace std;

// 值传递
void swap1(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

// 地址传递
void swap2(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 引用传递
void swap3(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main(int argc, const char *argv[]) {

    //    int a = 10;
    //    int &b = a;
    //    std::cout << b << std::endl;
    //
    //    b = 120;
    //
    //    std::cout << a << std::endl;
    //
    //    int c = 2000;
    //    //    &b = c; // 不可以操作
    //    b = c; // ok
    //    std::cout << a << std::endl;

    //    // 1. 值传递
    //    int x = 10, y = 20;
    //    swap1(x, y);
    //    cout << "x = " << x << "; y = " << y << endl;

    //    // 2. 地址传递
    //    int x = 10, y = 20;
    //    swap2(&x, &y);
    //    cout << "x = " << x << "; y = " << y << endl;

    // 3. 引用传递
    int x = 10, y = 20;
    swap3(x, y);
    cout << "x = " << x << "; y = " << y << endl;

    return 0;
}

// 1. 值传递

// 2. 地址传递

// 3. 引用传递
