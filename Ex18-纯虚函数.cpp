#include <iostream>
#include <string>
using namespace std;

class BaseClass
{
public:
    // 纯虚函数：纯虚函数必须包含在抽象类中
    virtual void speak(string text) = 0;
};

class Son : public BaseClass
{
public:
    virtual void speak(string text)
    {
        cout << "son speak" << " - " << text << endl;
    }
};

void test01()
{
    Son s1;
    s1.speak("hello world!");

    BaseClass *base = new Son;
    base->speak("baseclass invoke son ");
}

int main()
{
    test01();
    return 0;
}

/*
    抽象类特点：
    1、无法实例化对象
    2、抽象类的子类必须重写父类中的纯虚函数，否则子类也是抽象类
*/