#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 m_name;
    T2 m_age;
    Person(T1 _name, T2 _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }
    void show()
    {
        cout << "Name: " << this->m_name << ", Age: " << this->m_age << endl;
    }
};

void test01()
{
    Person<string, int> p1("steve", 18);
    p1.show();
}

int main()
{
    test01();
    return 0;
}