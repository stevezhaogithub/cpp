#include <iostream>

// max pig
void test1()
{
    int weights[5] = {300, 350, 200, 400, 250};
    int max = weights[0];
    for (int i = 1; i < 5; i++)
    {
        if (weights[i] > max)
        {
            max = weights[i];
        }
    }
    std::cout << "体重最重的小猪: " << max << std::endl;
}

// reverse array
void test2()
{
    int weights[5] = {300, 350, 200, 400, 250};

    for (int i = 0; i < 5 / 2; i++)
    {
        int temp = weights[i];
        weights[i] = weights[5 - i - 1];
        weights[5 - i - 1] = temp;
    }

    // 输出
    for (int i = 0; i < 5; i++)
    {
        std::cout << weights[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    // test1();
    test2();
    return 0;
}