/**
 * 数组中存放 5 个英雄, 然后按照英雄年龄进行升序排序
 *
 *
 */

#include <iostream>
#include <string>
struct Hero
{
    std::string name;
    int age;
    std::string _gender;
};

// 不能是只读的
void sort_asc(struct Hero *_heroes, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (_heroes[j].age > _heroes[j + 1].age)
            {
                struct Hero temp = _heroes[j];
                _heroes[j] = _heroes[j + 1];
                _heroes[j + 1] = temp;
            }
        }
    }
}

// 只读
void print_heroes(const struct Hero *_heroes, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << _heroes[i].name << ", " << _heroes[i].age << ", " << _heroes[i]._gender << std::endl;
    }
}
int main()
{
    struct Hero heroes[5] = {
        {"刘备", 23, "男"},
        {"张飞", 21, "男"},
        {"关羽", 20, "男"},
        {"赵云", 19, "男"},
        {"黄忠", 18, "男"}};
    // 按照年龄升序排序
    sort_asc(heroes, 5);

    // 输出英雄信息
    print_heroes(heroes, 5);

    return 0;
}
