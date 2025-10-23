/*
    实现一个通用的数组类
*/

#include <iostream>
#include <string>
#include "ZSteveArray.hpp"
using namespace std;

void test01()
{
    ZSteveArray<int> array1(10);
    ZSteveArray<int> array2(array1);
    ZSteveArray<int> array3(100);
    array3 = array1;
}

void print_numbers(ZSteveArray<int> &nums)
{
    for (int i = 0; i < nums.get_size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void test02()
{
    ZSteveArray<int> nums(15);
    for (int i = 0; i < 5; i++)
    {
        nums.push_tail(i + 2);
    }
    cout << "nums 数组中的元素为：" << endl;
    print_numbers(nums);

    cout << "nums 的容量为：" << nums.get_capacity() << endl;
    cout << "nums 的大小为：" << nums.get_size() << endl;

    cout << "-----------------------------------" << endl;

    ZSteveArray<int> nums2(nums);

    cout << "进行一次尾删" << endl;
    // 进行一次尾删
    nums2.pop_tail();

    cout << "nums2 数组中的元素为：" << endl;
    print_numbers(nums2);

    cout << "nums2 的容量为：" << nums2.get_capacity() << endl;
    cout << "nums2 的大小为：" << nums2.get_size() << endl;
}

class Person
{
public:
    Person()
    {
    }
    Person(string _name, int _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }
    string m_name;
    int m_age;
};

void print_people(ZSteveArray<Person> &list)
{
    for (int i = 0; i < list.get_size(); i++)
    {
        cout << "Person 1: " << list[i].m_name << ", " << list[i].m_age << endl;
    }
}

void test03()
{
    ZSteveArray<Person> people(10);

        Person p1("张三", 20);
    Person p2("李四", 22);
    Person p3("王五", 24);
    people.push_tail(p1);
    people.push_tail(p2);
    people.push_tail(p3);

    cout << "容量：" << people.get_capacity() << endl;
    cout << "大小：" << people.get_size() << endl;
    print_people(people);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}