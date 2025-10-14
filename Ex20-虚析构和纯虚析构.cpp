#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal 的构造函数" << endl;
    }

    // // 此处不加 virtual 关键字，则该析构函数不会被执行
    // virtual ~Animal()
    // {
    //     cout << "~Animal 的析构函数" << endl;
    // }

    // 纯虚析构函数(即需要声明，也需要实现)
    virtual ~Animal() = 0;

public:
    virtual void speak() = 0;
};

// Animal的纯虚析构函数实现
Animal::~Animal()
{
    cout << "Animal的纯虚析构函数被调用了" << endl;
}

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat 的构造函数" << endl;
        // 在堆区创建一块内存
        this->catName = new string(name);
    }
    virtual void speak()
    {
        cout << *catName << " - 小猫在讲话！" << endl;
    }
    virtual ~Cat()
    {
        if (catName != NULL)
        {
            cout << "~Cat的析构函数" << endl;
            delete catName;
            catName = NULL;
        }
    }

       string *catName;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    delete animal;
}

int main()
{
    test01();
    return 0;
}
