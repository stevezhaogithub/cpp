#include <iostream>
#include <string>
using namespace std;

// 普通计算器
class Calculator
{
public:
    int a;
    int b;

    int calculate(string opt)
    {
        if (opt == "+")
        {
            return a + b;
        }
        else if (opt == "-")
        {
            return a - b;
        }
        else if (opt == "*")
        {
            return a * b;
        }
        else if (opt == "/")
        {
            return a / b;
        }
        else
        {
            // 取余
            return a % b;
        }
    }
};

// 通过多态实现计算器
class CalculatorBase
{
public:
    int a;
    int b;
    virtual int calculate()
    {
        return 0;
    }
};

class Add : public CalculatorBase
{
    int calculate()
    {
        return a + b;
    }
};


class Minus : public CalculatorBase
{
    int calculate()
    {
        return a + b;
    }
};





int main()
{

    Calculator cal;
    cal.a = 10;
    cal.b = 20;

    int result = cal.calculate("%");
    cout << result << endl;
    return 0;
}

/*
    普通计算器
*/