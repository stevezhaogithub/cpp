#include <iostream>
#include <string>
using namespace std;

// 类做友元

class House;
class Student
{

public:
    Student();
public:
    House *_house;

    // 该函数中访问 House 中的成员
    void visit();
};


class House
{

    // 友元
    // Student 类是本类（House）的好朋友，可以i访问本类的私有成员
    friend class Student;

public:
    House();

public:
    // 客厅
    string m_livingRoom;
private:
    // 卧室
    string m_bedRoom;

};


// 在类外部写成员函数
House::House()
{
    m_livingRoom = "客厅";
    m_bedRoom = "卧室";
}

Student::Student()
{
    // 创建一个 House 对象
    _house = new House;
}

void Student::visit()
{
    cout << "Student 类正在访问：" << _house->m_livingRoom << endl;
    cout << "Student 类正在访问：" << _house->m_bedRoom << endl;
}

void test01()
{
    Student ss;
    ss.visit();
}
int main()
{
    test01();
    return 0;
}














