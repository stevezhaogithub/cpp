#include <iostream>
using namespace std;

class Person
{
public:
    int m_A;
    int m_B;
};

void test01()
{
    Person p;
    p.m_A = 10;
    p.m_B = 20;

    cout << &p << endl;
}

int main()
{
    return 0;
}