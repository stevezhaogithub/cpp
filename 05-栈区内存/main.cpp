//
//  main.cpp
//  05-栈区内存
//
//  Created by steve xiaohu zhao on 2025/9/29.
//

#include <iostream>
using namespace std;

// 不要返回局部变量地址
int *func() {
    // a 变量数据存储在栈区，函数执行完毕后自动释放
    int a = 10;
    return &a;
}

int main(int argc, const char *argv[]) {
    //
    int *p =func();
    
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}
