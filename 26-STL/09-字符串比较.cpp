#include <iostream>
#include <string>
using namespace std;

// 字符串比较
void test01()
{
    string str1 = "xello";
    string str2 = "hello";
    int ret = str1.compare(str2);
    // ret = 'x' - 'h' -> 16
    cout << "ret = " << ret << endl;
    if (str1.compare(str2) == 0)
    {
        cout << "str1 == str2" << endl;
    }
    else if (ret > 0)
    {
        cout << "str1 > str2" << endl;
    }
    else
    {
        cout << "str1 < str2" << endl;
    }
}
int main()
{
    test01();
    return 0;
}
