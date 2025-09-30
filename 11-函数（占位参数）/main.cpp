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

int main(int argc, const char *argv[]) {

    // 调用的时候，第二个整型参数必须传入
    func(100, 200);
    func2(10);
    return 0;
}

/*
    占位参数也可以有默认参数
*/
