#include <iostream>
using namespace std;

class Animal
{
public:
    // 虚函数。当在函数前增加 virtual 关键字后。实现了地址晚绑定，即实现了动态多态
    virtual void speak()
    {
        cout << "animal speak!" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "cat is speaking!" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "dog is speaking!" << endl;
    }
};

void doSpeak(Animal &animal)
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

int main()
{
    test01();
    return 0;
}