#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 员工基类
class Employee
{
public:
    string m_no;
    string m_name;
    string m_postName;
    string m_jobDesc;
};

// 老板
class Boss : public Employee
{
};

// 经理
class Manager : public Employee
{
};

int main()
{
    return 0;
}