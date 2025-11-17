/**
 *
 * 问题:
 *      当结构体作为函数参数的时候:
 *      1. 如果用值传递, 每次传递参数都复制一个结构体变量的全部数据, 太占内存
 *      2. 如果用地址传递（即参数是指针类型）, 虽然解决了每次传递参数复制整个结构体变量的问题，但在函数内部可以修改该结构体变量的值, 这种情况有时候是不希望发生的
 *      3. 通过将参数设置为指向常量的指针即可解决第2条种的问题 const Student * p
 */

#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int age;
    double score;
};

// const 关键字使用
void print_student(const Student *s)
{
    // error: cannot assign to variable 's' with const-qualified type 'const Student *'
    // s->age = 100; // 赋值语句报错
    std::cout << s->name << ", " << s->age << ", " << s->score << std::endl;
}

int main()
{
    struct Student s;
    s.age = 10;
    s.name = "steve";
    s.score = 99.5;
    print_student(&s);
}