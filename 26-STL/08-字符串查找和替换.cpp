#include <iostream>
#include <string>
using namespace std;

// 查找
void test01()
{
    string str1 = "abcdefgde";

    // 从左向右查找
    int pos = str1.find("de");       // 找到子字符串返回对应的索引，找不到返回 -1
    cout << "pos = " << pos << endl; // 3

    pos = str1.find("df");
    cout << "pos = " << pos << endl; // -1

    // rfind() 从最右侧开始查找
    pos = str1.rfind("de");
    cout << "rfind() pos = " << pos << endl; // 7
}

// 替换
void test02()
{
    string str1 = "abcdefg";

    // 从索引为 1 的 位置起，将 3 个字符替换为后面的字符串 "11111111"
    str1 = str1.replace(1, 3, "11111111");
    cout << "str1 = " << str1 << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}