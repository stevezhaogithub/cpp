#include <iostream>

int main()
{
    int scores[3][3] = {
        {100, 90, 89},
        {99, 78, 98},
        {100, 98, 87}};

    // 统计每个人的总分和平均分
    int columns = sizeof(scores[0]) / sizeof(scores[0][0]);
    int rows = sizeof(scores) / sizeof(scores[0]);
    // 循环每一行
    for (int i = 0; i < rows; ++i)
    {
        int sum = 0;
        double average = 0;
        // 循环每一列
        for (int j = 0; j < columns; ++j)
        {
            sum += scores[i][j];
        }
        average = (double)sum / (double)columns;
        std::cout << "第" << (i + 1) << "位同学的总成绩: " << sum << ", 平均分: " << average << std::endl;
    }
    return 0;
}