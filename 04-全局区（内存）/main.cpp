//
//  main.cpp
//  04-全局区（内存）
//
//  Created by steve xiaohu zhao on 2025/9/29.
//

#include <iostream>
using namespace std;

// 1. 定义两个全局变量
int ag = 100;
int bg = 200;

// 5. 全局常量
const int agc = 1000;
const int bgc = 1000;

int main(int argc, const char *argv[]) {
    // 全局区：全局变量、静态变量、常量

    // 2. 创建一个普通局部变量
    int a = 10;
    int b = 20;
    //    cout << &a << endl;
    //    cout << &b << endl;
    cout << "-----局部变量地址-----------------------" << endl;
    cout << (long)&a << endl;
    cout << (long)&b << endl;
    cout << "----------下面是全局变量的内存地址：------------------" << endl;
    cout << (long)&ag << endl;
    cout << (long)&bg << endl;

    // 3. 创建静态变量
    static int as = 100;
    static int bs = 200;
    cout << "----------下面是静态变量的内存地址：------------------" << endl;
    cout << (long)&as << endl;
    cout << (long)&bs << endl;

    // 4. 常量
    // 4.1 字符串常量
    string str = "Hello World";

    // 4.2 const 修饰的变量
    const int aconst = 100;

    cout << "------字符串常量的地址：------------" << endl;
    cout << (long)&str << endl;
    cout << "------const修饰的局部变量的地址：------------" << endl;
    cout << (long)&aconst << endl;

    cout << "------全局 const 修饰的变量的地址：------------" << endl;
    cout << (long)&agc << endl;
    cout << (long)&bgc << endl;

    return 0;
}
