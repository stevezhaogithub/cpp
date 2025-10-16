#include <iostream>
using namespace std;

// 动物类
class Animal
{
public:
    int age;
    Animal()
    {
        age = 10;
    }
};

// 马类
class Horse : public Animal
{
};

// 驴类
class Donkey : public Animal
{
};

// 骡子类
class Mule : public Horse, public Donkey
{
};

void test01()
{
    Mule mule;

    // 输出结果是 8
    cout << sizeof(mule) << endl;
    mule.Horse::age = 100;
    mule.Donkey::age = 900;
    cout << mule.Horse::age << endl;
    cout << mule.Donkey::age << endl;
}

int main()
{
    test01();
    return 0;
}

/*
菱形继承的本质问题是：同一个基类被多次继承，导致成员重复与二义性。
解决办法：虚拟继承（virtual inheritance），让最底层派生类只保留一份基类实例。
*/