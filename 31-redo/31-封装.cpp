#include <iostream>
#include <string>

// 圆周率
const double PI = 3.14;

class Circle
{
private:
    // 半径
    double m_r;

public:
    void set_m_r(double _r)
    {
        this->m_r = _r;
    }

    double get_m_r()
    {
        return this->m_r;
    }

    // 计算周长
    double get_zc()
    {
        return 2 * PI * m_r;
    }

    // 计算面积
    double get_area()
    {
        return PI * m_r * m_r;
    }
};

class Student
{
private:
    std::string m_name;
    int m_no;

public:
    void set_name(std::string _name)
    {
        this->m_name = _name;
    }
    std::string get_name()
    {
        return this->m_name;
    }

    void set_no(int _no)
    {
        this->m_no = _no;
    }
    int get_no()
    {
        return this->m_no;
    }
    void show_info()
    {
        std::cout << "姓名: " << this->get_name() << ", 学号: " << this->get_no() << std::endl;
    }
};

int main()
{
    Circle c1;
    c1.set_m_r(10);
    double zc = c1.get_zc();
    double area = c1.get_area();
    std::cout << "周长 = " << zc << std::endl;
    std::cout << "面积 = " << area << std::endl;

    std::cout << "--------------------------" << std::endl;
    Student s1;
    s1.set_name("张三");
    s1.set_no(1001);
    s1.show_info();

    return 0;
}