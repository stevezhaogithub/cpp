#include <iostream>
#include <string>
using namespace std;

// 抽象基类
class AbstractDrinking
{
public:
    // 煮水
    virtual void boil() = 0;

    // 冲泡
    virtual void brew() = 0;

    // 倒入杯中
    virtual void pourInCup() = 0;

    // 加入辅料
    virtual void putIn() = 0;
    // 制作饮品
    void makeDrink()
    {
        boil();
        brew();
        pourInCup();
        putIn();
    }
};

// 咖啡
class Coffe : public AbstractDrinking
{
    // 煮水
    virtual void boil()
    {
        cout << "煮水：农夫山泉。" << endl;
    }

    // 冲泡
    virtual void brew()
    {
        cout << "冲泡咖啡。" << endl;
    }

    // 倒入杯中
    virtual void pourInCup()
    {
        cout << "倒入瑞幸咖啡杯中。" << endl;
    }

    // 加入辅料
    virtual void putIn()
    {
        cout << "加入糖和牛奶" << endl;
    }
};

// 茶
class Tea : public AbstractDrinking
{
    // 煮水
    virtual void boil()
    {
        cout << "煮水： 怡宝矿泉水。" << endl;
    }

    // 冲泡
    virtual void brew()
    {
        cout << "冲泡 - 绿茶。" << endl;
    }

    // 倒入杯中
    virtual void pourInCup()
    {
        cout << "倒入玻璃杯中。" << endl;
    }

    // 加入辅料
    virtual void putIn()
    {
        cout << "加入 柠檬。" << endl;
    }
};

void doWork(AbstractDrinking *absd)
{
    absd->makeDrink();
}

void test01()
{

    doWork(new Coffe);

    doWork(new Tea);
}

int main()
{
    test01();
    return 0;
}