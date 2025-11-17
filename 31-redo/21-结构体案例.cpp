#include <iostream>
#include <string>
#include <random>
#include <ctime>

struct Student
{
    std::string name;
    int age;
    double score;
};

struct Teacher
{
    std::string name;
    int age;
    struct Student stus[5];
};

// 为 Teacher 数组加载数据
void load_data(struct Teacher *t, int size);

// 输出所有老师信息
void print_teachers(const struct Teacher *t, int size);

int main()
{

    // 设置随机数种子
    srand((unsigned int)time(NULL));

    // 1. 创建教师数组
    struct Teacher teachers[3];

    // 2. 通过函数为该数组赋值
    load_data(teachers, 3);

    // 3. 输出所有老师信息
    print_teachers(teachers, 3);

    return 0;
}

// 为 Teacher 数组加载数据
void load_data(struct Teacher *t, int size)
{
    int age_r = rand() % 41 + 20;
    std::string _nameSeed = "ABC";
    for (int i = 0; i < size; ++i)
    {
        t[i].age = age_r;
        t[i].name = std::string("老师-") + _nameSeed[i];
        // 计算学生数组的长度
        int L = sizeof(t[i].stus) / sizeof(t[i].stus[0]);

        for (int j = 0; j < L; ++j)
        {
            double score_r = rand() % 41 + 60;
            t[i].stus[j].name = std::string("学生") + _nameSeed[j];
            t[i].stus[j].age = (j + 1) * 5;
            t[i].stus[j].score = score_r;
        }
    }
}

// 输出所有老师信息
void print_teachers(const struct Teacher *t, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << t[i].name << ", " << t[i].age << ", " << std::endl;
        std::cout << "-----学生信息: " << std::endl;
        int L = sizeof(t[i].stus) / sizeof(t[i].stus[0]);
        for (int j = 0; j < L; ++j)
        {
            std::cout << "\t" << t[i].stus[j].name << ", " << t[i].stus[j].age << ", " << t[i].stus[j].score << std::endl;
        }
    }
}

/**
 * 生成随机数步骤:
 * 1. #include <ctime>
 * 2. srand((unsigned int)time(NULL));
 * 3. rand() % 10; // 生成 0~9的随机数
 *
 */