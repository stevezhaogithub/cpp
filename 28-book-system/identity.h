#pragma once
#include <iostream>
using namespace std;

// 身份类 - 抽象基类
class Identity
{
public:
    // 菜单 - 纯虚函数 - 不同的身份具有不同的菜单显示
    virtual void show_menu() = 0;
    string m_name;
    string m_passwd;
};

/*
    抽象类因为不需要实现，所以只要有 .h 头文件就可以了，不需要创建 .cpp 文件
*/