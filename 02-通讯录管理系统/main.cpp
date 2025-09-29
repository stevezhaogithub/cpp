//
//  main.cpp
//  02-通讯录管理系统
//
//  Created by steve xiaohu zhao on 2025/9/28.
//

// 1. 编写 show_menu() 函数
// 2.

#include <iostream>
#define MAX 1000
using namespace std;

// 创建联系人结构体
struct Person {
    string m_name;
    int m_sex; // 1男, 2女
    int m_age;
    string m_phone;
    string m_addr;
};

// 创建通讯录结构体
struct AddressBook {
    // 通讯录可以保存的总人数
    struct Person contacts[MAX];
    int m_size; // 当前通讯录中保存的联系人个数
};

// 返回 -1 表示联系人不存在，否则返回值表示联系人的序号（索引）
int check_user(struct AddressBook *adBook, string name) {
    for (int i = 0; i < adBook->m_size; i++) {
        if (adBook->contacts[i].m_name == name) {
            return i;
        }
    }
    return -1;
}

void show_menu() {
    cout << "*************************" << endl;
    cout << "*****  1. 添加联系人  *****" << endl;
    cout << "*****  2. 显示联系人  *****" << endl;
    cout << "*****  3. 删除联系人  *****" << endl;
    cout << "*****  4. 查找联系人  *****" << endl;
    cout << "*****  5. 修改联系人  *****" << endl;
    cout << "*****  6. 清空联系人  *****" << endl;
    cout << "*****  0. 退出通讯录  *****" << endl;
}

void add_contact(struct AddressBook *adb) {
    // 判断通讯录是否已经满了
    if (adb->m_size == MAX) {
        cout << "通讯录已满，无法添加联系人！" << endl;
        return;
    } else {
        // 添加联系人
        string name;
        cout << "请输入姓名：";
        cin >> name;

        int sex;
        cout << "请输入性别（1男，2女）：";
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                break;
            } else {
                cout << "性别只能输入1或2." << endl;
            }
        }

        int age;
        cout << "请输入年龄(0-150)：";
        while (true) {
            cin >> age;
            if (age >= 0 && age <= 150) {
                break;
            } else {
                cout << "输入年龄不在合法范围内！" << endl;
            }
        }

        string phone;
        cout << "请输入电话：";
        cin >> phone;

        string address;
        cout << "请输入通信地址：";
        cin >> address;

        // 将输入的数据添加到通讯录
        adb->contacts[adb->m_size].m_name = name;
        adb->contacts[adb->m_size].m_sex = sex;
        adb->contacts[adb->m_size].m_age = age;
        adb->contacts[adb->m_size].m_phone = phone;
        adb->contacts[adb->m_size].m_addr = address;

        // 更新通讯录中的人数
        adb->m_size++;
        cout << "联系人添加成功！" << endl;

        // 清屏
        // system("clear");
    }
}

// 显示所有联系人
void show_contacts(struct AddressBook *adBook) {
    // 判断通讯录中是否有联系人
    if (adBook->m_size > 0) {
        // 显示所有联系人
        for (int i = 0; i < adBook->m_size; i++) {
            struct Person model = adBook->contacts[i];
            cout << "姓名：" << model.m_name << endl;
            cout << "性别：" << ((model.m_sex == 1) ? "男" : "女") << endl;
            cout << "年龄：" << model.m_age << endl;
            cout << "电话：" << model.m_phone << endl;
            cout << "通信地址：" << model.m_addr << endl;
            cout << "---------------------------------" << endl;
        }
    } else {
        cout << "您的联系人列表为空！" << endl;
    }
}

// 删除联系人（根据姓名删除联系人）
void delete_contact(struct AddressBook *adBook, string name) {
    // 判断联系人是否存在
    int idx = -1;

    if ((idx = check_user(adBook, name)) != -1) {
        // 执行删除操作
        // cout << "联系人存在！" << endl;

        // 从长度为 1000 的数组中删除查询到的联系人(后面的数据向迁移，总人数
        // -1）
        for (int i = idx; i < adBook->m_size; i++) {
            adBook->contacts[i] = adBook->contacts[i + 1];
        }
        adBook->m_size--;
        cout << "联系人删除成功！" << endl;

    } else {
        cout << "要删除的联系人不存在！" << endl;
    }
}

// 查找联系人
void search_contact(struct AddressBook *adBook) {
    cout << "请输入要查找的联系人姓名：" << endl;
    string name;
    cin >> name;

    // 判断联系人是否存在
    int idx = -1;
    if ((idx = check_user(adBook, name)) != -1) {
        // 找到该联系人了, 显示该联系人的信息
        cout << "姓名：" << adBook->contacts[idx].m_name << endl;
        cout << "性别：" << ((adBook->contacts[idx].m_sex == 1) ? "男" : "女")
             << endl;
        cout << "年龄：" << adBook->contacts[idx].m_age << endl;
        cout << "电话：" << adBook->contacts[idx].m_phone << endl;
        cout << "通信地址：" << adBook->contacts[idx].m_addr << endl;

    } else {
        cout << "查无此人！" << endl;
    }
}

// 修改联系人
void edit_contact(AddressBook *adBook) {

    cout << "请输入要修改的联系人姓名：";
    string name;
    cin >> name;

    // 1. 判断联系人是否存在
    int idx = -1;
    if ((idx = check_user(adBook, name)) != -1) {
        // 2. 要修改的用户存在,  进行修改
        string edit_name;
        cout << "请输入姓名：";
        cin >> edit_name;

        int edit_age;
        cout << "请输入年龄：";
        cin >> edit_age;

        int edit_sex;
        cout << "请输入性别(1男，2女)：";
        while (true) {
            cin >> edit_sex;
            if (edit_sex == 1 || edit_sex == 2) {
                break;
            } else {
                cout << "性别只能输入 1 或 2 。" << endl;
            }
        }

        string edit_phone;
        cout << "请输入电话：";
        cin >> edit_phone;

        string edit_addr;
        cout << "请输入通信地址：";
        cin >> edit_addr;

        adBook->contacts[idx].m_name = edit_name;
        adBook->contacts[idx].m_age = edit_age;
        adBook->contacts[idx].m_sex = edit_sex;
        adBook->contacts[idx].m_phone = edit_phone;
        adBook->contacts[idx].m_addr = edit_addr;

        cout << "修改成功！" << endl;
    } else {
        cout << "您输入的姓名不存在！" << endl;
    }
}

// 清空联系人
void empty_contacts(struct AddressBook *adBook) {
    string confirm;
    cout << "确定要清空通讯录吗？(y/n)";
    cin >> confirm;
    if (confirm == "y") {
        // 把 size 设置为 0
        adBook->m_size = 0;
        cout << "通讯录已清空！" << endl;
    } else {
        cout << "退出，通讯录未清空！" << endl;
    }
}

int main(int argc, const char *argv[]) {

    // 创建通讯录结构体变量
    AddressBook adbook;
    // 初始化当前联系人个数为 0
    adbook.m_size = 0;

    // 接受用户菜单选项
    int selected = 0;

    while (true) {
        // 1. 显示菜单
        show_menu();

        // 2. 系统操作
        // 接受用户的输入
        cin >> selected;
        switch (selected) {
        case 1:
            // 1. 添加联系人
            add_contact(&adbook);
            break;
        case 2:
            // 2. 显示联系人
            show_contacts(&adbook);
            break;
        case 3: {
            // 3. 删除联系人
            cout << "请输入要删除的联系人姓名：";
            // 在 case 语句中定义了变量，所以必须在该 case 语句中用 {}
            string name;
            cin >> name;
            delete_contact(&adbook, name);
            break;
        }
        case 4:
            // 4. 查找联系人
            search_contact(&adbook);
            break;
        case 5:
            // 5. 修改联系人
            edit_contact(&adbook);
            break;
        case 6:
            // 6. 清空联系人
            empty_contacts(&adbook);
            break;
        case 0:
            // 0. 退出通讯录
            cout << "欢迎下次继续使用！" << endl;
            exit(0);
            break;
        default:
            // 用户输入错误
            cout << "输入错误！" << endl;
            break;
        }
    }

    return 0;
}
