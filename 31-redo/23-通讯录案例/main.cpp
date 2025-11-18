
/**
 *
 * switch case 中如果代码量太大, 用 {} 包含
 */

#include <iostream>
#include <string>
#include <iomanip>
#define __MAX_CONTACTS__ 1000

// 设计联系人的结构体
struct Contact
{
    std::string m_name;
    int m_gender; // 1男, 2女
    int m_age;
    std::string m_phone;
    std::string m_address;
};

// 设计通讯录结构体
struct AddressBook
{
    // 联系人数组
    struct Contact contacts[__MAX_CONTACTS__];
    // 当前联系人个数
    int m_size;
};

// 显示主菜单
void show_menu();

// 添加联系人(将通讯录对象作为参数传递到函数中)
void add_contact(struct AddressBook *_adb);

// 显示联系人
void show_contacts(const struct AddressBook *_adb);

// 根据姓名, 判断某人是否存在
// 如果找到了, 返回对应的下标索引, 如果没有找到返回 -1
int is_exists(const struct AddressBook *_adb, std::string name);

// 删除联系人
void delete_contact(struct AddressBook *_adb);

// 查找指定的联系人
void find_contact(struct AddressBook *_adb);

// 程序主函数
int main()
{
    // 创建通讯录结构体, 并初始化 m_size
    struct AddressBook adb;
    adb.m_size = 0;

    while (true)
    {
        // 1. 显示主菜单
        show_menu();

        // 2. 接收用户的选择
        int selected = -1;
        std::cin >> selected;
        // 判断用户输入
        switch (selected)
        {
        case 1:
            // 添加联系人
            add_contact(&adb);
            break;
        case 2:
            // 显示联系人
            show_contacts(&adb);
            break;
        case 3:
            // 删除联系人
            delete_contact(&adb);
            break;
        case 4:
            // 查找联系人
            find_contact(&adb);
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            while (true)
            {
                char ch;
                std::cout << "确认退出吗(y/n) ";
                std::cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    exit(0);
                }
                else
                {
                    system("clear");
                    break;
                }
            }
            break;
        }
    }

    return 0;
}

// 显示主菜单
void show_menu()
{
    std::cout << "-----------欢迎使用通讯录系统------------" << std::endl;
    std::cout << "1. 添加联系人" << std::endl;
    std::cout << "2. 显示联系人" << std::endl;
    std::cout << "3. 删除联系人" << std::endl;
    std::cout << "4. 查找联系人" << std::endl;
    std::cout << "5. 编辑联系人" << std::endl;
    std::cout << "6. 清空联系人" << std::endl;
    std::cout << "0. 退出系统" << std::endl;
    std::cout << "请输入要进行的操作: ";
}

// 添加联系人
void add_contact(struct AddressBook *_adb)
{
    // 判断通讯录是否已满
    if (_adb->m_size == __MAX_CONTACTS__)
    {
        std::cout << "通讯录已满, 无法添加新纪录!" << std::endl;
        return;
    }
    // 提示用户输入信息, 并且将该信息添加到通讯录中
    struct Contact model;
    std::cout << "请输入姓名: ";
    std::cin >> model.m_name;
    while (true)
    {
        std::cout << "请输入性别（1男, 2女）: ";
        std::cin >> model.m_gender;
        if (model.m_gender == 1 || model.m_gender == 2)
        {
            break;
        }
        else
        {
            model.m_gender = 0;
            std::cout << "输入不合法, 性别只能输入1或2, 请重新输入!" << std::endl;
        }
    }
    std::cout << "请输入年龄: ";
    std::cin >> model.m_age;
    std::cout << "请输入电话: ";
    std::cin >> model.m_phone;
    std::cout << "请输入通讯地址: ";
    std::cin >> model.m_address;

    // 添加到通讯录数组中
    _adb->contacts[_adb->m_size++] = model;
    std::cout << "添加成功！" << std::endl;
    std::cin.ignore();
    std::cout << "输入 Enter 键继续..." << std::endl;
    std::cin.get();
    system("clear");
}

// 显示联系人
void show_contacts(const struct AddressBook *_adb)
{
    if (_adb->m_size <= 0)
    {
        std::cout << "通讯录为空！" << std::endl;
    }
    else
    {
        // 循环显示每个联系人信息
        for (int i = 0; i < _adb->m_size; ++i)
        {
            struct Contact model = _adb->contacts[i];
            std::cout << (i + 1) << ". "
                      << std::left << std::setw(20)
                      << model.m_name << " | " << model.m_gender << " | " << model.m_age << " | " << model.m_phone << " | " << model.m_address << std::endl;
        }
    }
    std::cin.ignore();
    std::cout << "按 Enter 键继续..." << std::endl;
    std::cin.get();
    system("clear");
}

// 删除联系人
void delete_contact(struct AddressBook *_adb)
{
    // 请用户输入要删除的人的姓名
    std::cout << "请输入要删除的人的姓名: ";
    std::string del_name;
    std::cin >> del_name;

    // 判断某人是否存在
    int ret = is_exists(_adb, del_name);
    if (ret == -1)
    {
        std::cout << "查无此人!" << std::endl;
    }
    else
    {
        // 执行删除操作
        for (int i = ret + 1; i < _adb->m_size; ++i)
        {
            _adb->contacts[i - 1] = _adb->contacts[i];
        }
        _adb->m_size--;
        std::cout << "删除成功!" << std::endl;
    }
}

// 根据姓名, 判断某人是否存在
// 如果找到了, 返回对应的下标索引, 如果没有找到返回 -1
int is_exists(const struct AddressBook *_adb, std::string name)
{
    for (int i = 0; i < _adb->m_size; ++i)
    {
        if (_adb->contacts[i].m_name == name)
        {
            return i;
        }
    }
    return -1;
}

// 查找指定的联系人
void find_contact(struct AddressBook *_adb)
{
    // 1. 判断通讯录是否为空
    if (_adb->m_size <= 0)
    {
        std::cout << "通讯录为空!" << std::endl;
        std::cin.ignore();
        std::cout << "按 Enter 键继续..." << std::endl;
        std::cin.get();
        system("clear");
    }
    else
    {
        std::string name;
        std::cout << "请输入要查找的联系人姓名: ";
        std::cin >> name;
        // 在通讯录数组中查找对应的联系人信息
        int ret = is_exists(_adb, name);
        if (ret == -1)
        {
            std::cout << "查无此人!" << std::endl;
            std::cin.ignore();
            std::cout << "按 Enter 键继续..." << std::endl;
            std::cin.get();
            system("clear");
        }
        else
        {
            // 显示查找到的联系人信息
            std::cout << _adb->contacts[ret].m_name << " | " << _adb->contacts[ret].m_gender << " | " << _adb->contacts[ret].m_age << " | " << _adb->contacts[ret].m_phone << " | " << _adb->contacts[ret].m_address << std::endl;
            std::cin.ignore();
            std::cout << "按 Enter 键继续..." << std::endl;
            std::cin.get();
            system("clear");
        }
    }
}
