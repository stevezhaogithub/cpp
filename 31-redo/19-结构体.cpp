/**
 *
 * 一、结构体定义
 *
 * 二、通过结构体创建变量: 3 种方式
 * 1. struct 结构体名 变量名
 * 2. struct 结构体名 变量名 = {成员1值, 成员2值,...}
 * 3. 定义结构体的时候顺便创建变量
 *
 *
 * 三、结构体数组
 *
 *
 * 四、结构体指针
 * 结构体指针，通过 -> 的方式访问结构体成员
 *
 *
 *
 */
#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int age;
    double score;
} s3, s4; // 在定义结构体的同时创建结构体变量s3 和 s4

// 结构体嵌套
struct Teacher
{
    int id;
    std::string name;
    int age;
    struct Student stu;
};

int main()
{
    // 1. 定义结构体变量

    // 方式一:
    // struct Student s1;
    // 在 c++ 中创建结构体变量的时候可以省略 struct 关键字
    Student s1;
    s1.name = "张三";
    s1.age = 19;
    s1.score = 99;
    std::cout << s1.name << ", " << s1.age << ", " << s1.score << std::endl;

    // 方式二:
    struct Student s2 = {"李四", 29, 98.5};
    std::cout << s2.name << ", " << s2.age << ", " << s2.score << std::endl;

    // 方式三: 在定义结构体的同时创建了结构体变量 s3 和 s4
    s3.name = "王五";
    s3.age = 17;
    s3.score = 89;
    std::cout << s3.name << ", " << s3.age << ", " << s3.score << std::endl;

    s4.name = "赵六";
    s4.age = 16;
    s4.score = 96;
    std::cout << s4.name << ", " << s4.age << ", " << s4.score << std::endl;
    std::cout << "----------------------------------" << std::endl;
    // 创建一个结构体数组
    struct Student stus[3] = {
        {"bob", 28, 99}, {"jerry", 18, 98}, {"tom", 8, 96}};
    for (int i = 0; i < 3; ++i)
    {
        std::cout << stus[i].name << ", " << stus[i].age << ", " << stus[i].score << std::endl;
    }

    std::cout << "----------------------------------" << std::endl;
    // 创建结构体指针
    struct Student *stu_ptr = &s1;
    std::cout << stu_ptr->name << ", " << stu_ptr->age << ", " << stu_ptr->score << std::endl;

    // 2. 结构体嵌套
    Teacher t;
    t.id = 1000;
    t.name = "叶圣陶";
    t.age = 30;
    t.stu.name = "李四";
    t.stu.age = 18;
    t.stu.score = 99;

    std::cout << "老师姓名: " << t.name << ", 老师的学生: ";
    std::cout << "\v学生姓名: " << t.stu.name << ", 成绩: " << t.stu.score << std::endl;

    return 0;
}