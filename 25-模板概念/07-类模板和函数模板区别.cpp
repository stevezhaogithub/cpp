#include <iostream>
#include <string>
using namespace std;

// 2、类模板在模板参数列表中可以有默认参数(AgeT 默认就是 int 类型)
// 只有类模板才可以有默认参数类型，函数模板不能这么用
template <class NameT, class AgeT = int>
class Person
{
public:
    NameT m_name;
    AgeT m_age;
    Person(NameT _name, AgeT _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }

    void show()
    {
        cout << this->m_name << " - " << this->m_age << endl;
    }
};

void test01()
{
    // 1、类模板没有自动类型推导
    // 编译器无法进行类型推断
    // 错误！
    // Person p1("steve", 18);

    // 正确
    // Person<string, int> p1("steve", 18);
    // 因为 AgeT 默认是 int 类型，所以这里可以不设置第二个类型参数
    Person<string> p1("steve", 18);
    p1.show();
}
int main()
{
    test01();
    return 0;
}

/*
    类模板 和 函数模板的区别：
    1、类模板没有自动类型推导
    2、类模板在模板参数列表中可以有默认参数
*/