#include <iostream>
#include <string>
using namespace std;

// 字符串的插入和删除
void test01()
{
    string str1 = "Hello";

    // 字符串插入：从索引为1的位置开始，插入 WWW 字符串
    str1.insert(1, "WWW");
    cout << "str1 = " << str1 << endl;

    // 删除:从索引为 1 的位置起，删除 3 个字符
    str1.erase(1, 3);
    cout << "str1 = " << str1 << endl;
}

// string 子串
void test02()
{
    string str = "abcdefg";
    // 截取子字符串
    string sub_str = str.substr(1, 3);
    cout << sub_str << endl;
}

void test03()
{
    string email = "hello@sina.com.cn";
    int idx = email.find('@', 0);
    // 从索引为 0 开始，截取 idx 个字符
    string _user_name = email.substr(0, idx);
    cout << _user_name << endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}