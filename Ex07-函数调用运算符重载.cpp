#include <iostream>
using namespace std;

// 打印输出类
class MyPrinter
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};

// 自定义加法类
// 仿函数使用非常灵活，没有固定的写法
class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

void test02()
{
    MyAdd addition;
    int result = addition(200, 300);
    cout << result << endl;

    // 先创建匿名对象，然后再调用 () 重载
    int ret = MyAdd()(2, 3);
    cout << "ret = " << ret << endl;
}

void show(string text)
{
    cout << text << endl;
}

void test01()
{
    MyPrinter printer;

    // 仿函数：使用起来就像函数一样
    printer("hello world text!!!");

    // 真正的函数调用
    show("Hello World in show!!");
}

int main()
{
    // test01();
    test02();
    return 0;
}