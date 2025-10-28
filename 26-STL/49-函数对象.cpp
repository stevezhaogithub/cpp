/*
    仿函数 - Functor

    函数对象（仿函数）
    - 重载函数调用操作符的类，其对象常叫做：函数对象
    - 函数对象（仿函数）是一个类不是一个函数


    函数对象的特点：
    1. 函数对象在使用时，可以有参数、返回值
    2. 函数对象超出了普通函数的概念，函数对象可以有自己的状态
    3. 函数对象可以作为参数传递


*/

#include <iostream>
#include <string>
using namespace std;

// 仿函数 MyAdd
class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

void test01()
{
    int x = 10, y = 100;
    MyAdd my_add;
    // 1. 函数对象在使用的时候，就像普通函数一样
    int ret = my_add(x, y);
    cout << "ret = " << ret << endl;
}

class MyPrint
{
private:
    // 2. 函数对象超出了普通函数的概念，函数对象可以有自己的状态
    // 通过 invoke_count 记录函数被调用的次数
    int invoke_count;

public:
    // 想统计一下这个函数被调用了多少次, 就需要在函数对象中保存状态
    void operator()(string text)
    {
        cout << text << endl;
        this->invoke_count++;
    }
    MyPrint()
    {
        this->invoke_count = 0;
    }
    void show_invoke_count()
    {
        cout << this->invoke_count << endl;
    }
};

void test02()
{
    MyPrint my_print;
    my_print("hello world");
    my_print("hello world");
    my_print("hello world");
    my_print("hello world");
    my_print("hello world");
    my_print.show_invoke_count();
}

void do_print(MyPrint &mp, string text)
{
    mp(text);
}

// 函数对象可以作为参数传递
void test03()
{
    MyPrint my_print;
    do_print(my_print, "Hello C Plus Plus");
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}