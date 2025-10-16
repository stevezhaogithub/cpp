
#include <iostream>
#include <string>
using namespace std;

// 返回局部变量的值（错误）
// 用引用的方式返回变量 a
int &test01() {
    int a = 10;
    return a;
}

int &test02() {
    static int a = 100;
    return a;
}

int main() {

    int &ref = test01();

    // 输出结果有问题
    cout << "ref = " << ref << endl;
    cout << "ref = " << ref << endl;

    cout << "-------------------------" << endl;
    int &res = test02();
    cout << "res = " << res << endl;
    cout << "res = " << res << endl;
    cout << "res = " << res << endl;
    
    
    
    // 作为左值
    test02() = 2000;
    
    cout << "res = " << res << endl;
    cout << "res = " << res << endl;

    return 0;
}
