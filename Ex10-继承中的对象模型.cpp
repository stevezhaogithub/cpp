#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son : public Base
{
public:
    int m_D;
};

int main()
{

    // 输出结果是 16
    // 父类中的 private 成员确实被继承下来了，但是编译器限制了对 private 成员的访问，所以无法访问
    cout << sizeof(Son) << endl;
    return 0;
}