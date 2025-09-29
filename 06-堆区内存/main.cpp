//
//  main.cpp
//  06-堆区内存
//
//  Created by steve xiaohu zhao on 2025/9/29.
//

#include <iostream>
#include <string>
using namespace std;

int * func() {
    // 在堆上开辟内存, new int(10) 返回的是一个 int 类型指针
    int *a = new int(10);
    return a;
}

int main(int argc, const char * argv[]) {
    
    // 在堆区开辟内存
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}
