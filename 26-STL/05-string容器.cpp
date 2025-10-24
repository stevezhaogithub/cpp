#include <iostream>
#include <string>
using namespace std;

void test01()
{
    // 1. 调用了默认无参构造函数
    string s1;

    // 2. 使用 char * 初始化字符串
    const char *str = "Hello World!";
    string s2(str);
    cout << "s2 = " << s2 << endl;

    // 3. 通过拷贝构造创建字符串
    string s3(s2);
    cout << "s3 = " << s3 << endl;

    // 通过 n 个字符 char 来初始字符串
    // 字符串 s4 由 10 个 'a' 组成
    string s4(10, 'a');
    cout << "s4  = " << s4 << endl;
}

int main()
{
    test01();
    return 0;
}
