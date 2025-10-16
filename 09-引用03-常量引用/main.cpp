//
//  main.cpp
//  09-引用03-常量引用
//
//  Created by steve xiaohu zhao on 2025/9/30.
//

#include <iostream>
using namespace std;

void show(const int &a) {
    // a = 10000; 这里不可以修改 a
    cout << "a = " << a << endl;
}

int main(int argc, const char *argv[]) {

    // int &ref = 10; // 错误
    const int &ref = 10; // 正确，等价于下面的代码
    /*
     int temp = 10;
     int &ref = temp;
     */

    // ref = 100; // 错误，因为 const 关键字，所以 ref 不能再重新赋值

    // 使用场景
    int a = 10;
    show(a);

    return 0;
}
