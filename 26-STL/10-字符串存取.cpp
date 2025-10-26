#include <iostream>
#include <string>
using namespace std;
// 1.通过下标访问字符串中的字符
// 2.通过 at() 访问每个字符

void test01()
{
    string str1 = "Hello";
    cout << str1 << endl;
    cout << "size(): " << str1.size() << endl;
    cout << "length(): " << str1.length() << endl;
    cout << "-------" << endl;
    for (int i = 0; i < str1.length(); i++)
    {
        cout << str1[i] << endl;
        cout << str1.at(i) << endl;
    }

    // 修改单个字符
    str1[0] = 'W';
    cout << str1 << endl;
    str1.at(1) = 'G';
    cout << str1 << endl;
}

void test02()
{
    string s = "中国a";
    size_t ssize = s.size();
    cout << "s.size() = " << ssize << endl;

    size_t llen = s.length();
    cout << "s.length() = " << llen << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}