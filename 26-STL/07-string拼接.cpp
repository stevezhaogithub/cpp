#include <iostream>
#include <string>
using namespace std;

// string 字符串拼接操作
void test01()
{

    // string & operator+=(const char *str)
    string str1 = "Hello World!";
    str1 += "你好世界！";
    cout << "str1 = " << str1 << endl;

    // string & operator+=(const char c)
    str1 += 'A';
    cout << "str1 = " << str1 << endl;

    // string & operator+=(const string &str)
    string str2 = "LOL DNF";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    // string & append(const char *str)
    string str3 = "I";
    str3.append(" love ");
    cout << "str3 = " << str3 << endl;

    // string & append(const char *str, int n)
    str3.append(" this game!哈哈哈哈哈哈", 11);
    cout << "str3 = " << str3 << endl;

    // string & append(const string &str);
    str3.append("BASKETBALL");
    cout << "str3 = " << str3 << endl;

    // string & append(const string &str, int pos, int n);
    // 从索引为 2 的开始，截取长度为 5
    str3.append("ABCDEFGHIJKLMNOPQ", 2, 5);
    cout << "str3 = " << str3 << endl;
}

int main()
{
    test01();
    return 0;
}