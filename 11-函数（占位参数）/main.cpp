//
//  main.cpp
//  11-函数（占位参数）
//
//  Created by steve xiaohu zhao on 2025/9/30.
//

#include <iostream>
using namespace std;

// 占位参数. 第二个参数就是占位参数
void func(int a, int) { cout << "this is a function." << endl; }

// 带有默认参数值的 “占位参数”
void func2(int a, int = 100) {
    cout << "it is a function with default value" << endl;
}

// 函数重载
int add(int a, int b) { return a + b; }

int add(int a, int b, int c) { return a + b + c; }

double add(double a, double b) { return a + b; }

double add(int a, double b) { return a + b; }

double add(double a, int b) { return a + b; }

// 函数重载的注意事项：
// 1、以下两个函数属于函数重载（参数的类型不同）

// void fun(int a); 和 void fun(int &a); 会发生歧义
// void fun(int a) {
//    cout << "fun(int a) 调用" << endl;
//}
void fun(int &a) { cout << "fun(int &a) 调用" << endl; }
void fun(const int &a) { cout << "fun(const int &a) 调用" << endl; }

// 函数重载的注意事项：
// 2、函数重载的默认参数
void fun2(int a) { cout << "fun2(int a) 被调用" << endl; }
void fun2(int a, int b = 10) {
    cout << "fun2(int a, int b = 10) 被调用" << endl;
}

int main(int argc, const char *argv[]) {

    // 调用的时候，第二个整型参数必须传入
    //    func(100, 200);
    //    func2(10);

    // int ret = add(10, 20, 300);
    double ret = add(10.8, 9.1);
    cout << ret << endl;

    // 函数重载注意事项
    int a = 100;
    fun(a); // 调用的是 fun(int &a) 函数
    cout << "---------------" << endl;
    fun(100); // 调用的是 fun(const int &a); 编译器会创建一个临时的 int temp

    // 函数重载的默认参数问题
    //    fun2(100);  // 此处的调用依然有歧义
    fun2(100, 200);

    return 0;
}

/*
    占位参数也可以有默认参数
*/
