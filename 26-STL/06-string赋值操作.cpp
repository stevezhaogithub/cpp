#include <iostream>
#include <string>
using namespace std;

/*
    string 的赋值操作
*/

void test01()
{
    string str1;

    // string & operator=(const char *s);
    str1 = "hello world!";
    cout << "str1 = " << str1 << endl;

    // 拷贝构造
    // string & operator=(const string &s);
    string str2 = str1;
    cout << "str2 = " << str2 << endl;

    // string & operator= (char c)
    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    // string & assign(const char *s)
    string str4;
    str4.assign("Hello C++");
    cout << "str4  = " << str4 << endl;

    // string & assign(const string &s)

    // string & assign(const char *s, int n)
    string str5;
    str5.assign("Hello C double plus", 5);
    cout << "str5 = " << str5 << endl; // Hello

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl; // Hello

    string str7;
    str7.assign(10, 'w');
    cout << "str7 = " << str7 << endl;
}
int main()
{
    test01();
    return 0;
}