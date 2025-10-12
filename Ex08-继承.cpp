#include <iostream>
using namespace std;

class BasePage
{
public:
    void header()
    {
        cout << "header" << endl;
    }

    void left()
    {
        cout << "left" << endl;
    }

    void right()
    {
        cout << "right" << endl;
    }

    void bottom()
    {
        cout << "bottom" << endl;
    }
};

class JavaPage : public BasePage
{
public:
    void content()
    {
        cout << "Java 学科" << endl;
    }
};

class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python 学科" << endl;
    }
};

class CPP : public BasePage
{
public:
    void content()
    {
        cout << "C++ 学科" << endl;
    }
};

int main()
{

    JavaPage java;
    java.header();
    java.bottom();
    java.left();
    java.right();
    java.content();

    Python py;
    py.header();
    py.bottom();
    py.left();
    py.right();
    py.content();
    return 0;
}