#include <iostream>
#include <string>
using namespace std;

int add(int a, int b = 200, int c = 300) { return a + b + c; }


int func(int a, int b = 20, int c = 100);

// 函数声明中已经有默认参数了，实现中就不能再出现默认参数了
int func(int a, int b, int c) {
    return a + b + c;
}

int main() {

    // 使用自己传入的值
    int ret1 = add(10, 20, 30);

    // 使用默认值
    int ret2 = add(100);

    cout << "ret1 = " << ret1 << endl;
    cout << "ret2 = " << ret2 << endl;
    return 0;
}


/*
    注意：
        1、如果从某个参数位置，开始出现了默认参数，那么从这个位置开始，后面的也必须有默认参数
        2、如果函数的声明有默认参数，那么函数的实现就不能有默认参数了。
        - 声明和实现智能有一个地方有默认参数
*/



























