//
//  WorkerManager.cpp
//  24-基于多态的职工管理系统
//
//  Created by steve xiaohu zhao on 2025/10/15.
//

#include "WorkerManager.hpp"
#include "Boss.hpp"
#include "Employee.hpp"
#include "Manager.hpp"
#include "Worker.hpp"
#include <fstream>
#include <iomanip>

#define FILENAME "employees.txt"

// 构造函数的实现
WorkerManager::WorkerManager()
{

    // 1. 读取文件，根据文件内容初始化成员变量
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        // 文件不存在
        cout << "文件不存在！" << endl;
        //  初始化人数
        this->m_count = 0;
        // 初始化指针数组
        this->m_employees = NULL;

        this->is_file_empty = true;
        ifs.close(); // 关闭文件流
    }
    else
    {
        // 文件存在
        char ch;
        // 读取一个字符到 ch 中
        ifs >> ch;
        // 1. 数据为空
        if (ifs.eof())
        {
            // 表示文件为空
            cout << "文件为空！" << endl;
            //  初始化人数
            this->m_count = 0;
            // 初始化指针数组
            this->m_employees = NULL;

            this->is_file_empty = true;
            ifs.close(); // 关闭文件流
        }
        else
        {

            // 2. 数据不为空
            int empNumber = this->get_emp_count();
            // cout << "员工人数为：" << empNumber << endl;
            this->m_count = empNumber;

            // 开辟空间
            this->m_employees = new Worker *[this->m_count];
            // 将文件中的数据读取到数组中
            this->init_employees();
        }
    }
}

// 析构函数的实现
WorkerManager::~WorkerManager()
{
    // 释放堆区数据
    if (this->m_employees != NULL)
    {
        delete[] this->m_employees;
        this->m_employees = NULL;
    }
}

// 显示菜单
void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "************* 欢迎使用职工管理系统 *************" << endl;
    cout << "*************  0. 退出管理程序   *************" << endl;
    cout << "*************  1. 增加职工信息   *************" << endl;
    cout << "*************  2. 显示职工信息   *************" << endl;
    cout << "*************  3. 删除离职员工   *************" << endl;
    cout << "*************  4. 修改职工信息   *************" << endl;
    cout << "*************  5. 查找职工信息   *************" << endl;
    cout << "*************  6. 按照编号排序   *************" << endl;
    cout << "*************  7. 清空所有文档   *************" << endl;
    cout << endl;
}

// 退出系统
void WorkerManager::exit_system()
{
    cout << "欢迎下次使用！" << endl;
    exit(0);
}

// 添加员工
void WorkerManager::addEmployee()
{
    cout << "请输入要增加的员工数量：";
    int count = 0;
    cin >> count;
    if (count > 0)
    {

        // 计算新空间大小
        int new_size = this->m_count + count;
        // 开辟新的空间(指针数组）
        Worker **new_space = new Worker *[new_size];

        // 将原空间下内容存放到新空间下
        if (this->m_employees != NULL)
        {
            for (int i = 0; i < this->m_count; i++)
            {
                new_space[i] = this->m_employees[i];
            }
        }

        // 循环输入新数据
        for (int i = 0; i < count; i++)
        {
            int _no;
            string _name;
            int _deptNo;

            cout << "请输入第" << i + 1 << "个员工编号：";
            cin >> _no;
            cout << "请输入第" << i + 1 << "个员工姓名：";
            cin >> _name;
            cout << "请输入第" << i + 1 << "个员工部门编号：";
            cin >> _deptNo;
            cout << "请选择该员工的职位：" << endl;
            cout << "1、普通员工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> _deptNo;

            Worker *wker = NULL;
            switch (_deptNo)
            {
            case 1:
                // 普通员工
                wker = new Employee(_no, _name, _deptNo);
                break;
            case 2:
                // 经理
                wker = new Manager(_no, _name, _deptNo);
                break;
            case 3:
                // 老板
                wker = new Boss(_no, _name, _deptNo);
                break;
            default:
                cout << "输入错误！" << endl;
                break;
            }
            // 将新增加的员工添加到 new_space 中
            new_space[this->m_count + i] = wker;
        }

        // 释放原有空间
        delete[] this->m_employees;

        // 更新空间指向
        this->m_employees = new_space;

        // 更新总人数
        this->m_count = new_size;

        // 更新员工不为空的标志
        this->is_file_empty = false;

        // 提示信息
        cout << "成功添加 " << count << " 名新员工！" << endl;
        // 保存数据到文件
        save();
        cin.ignore(); // 忽略一个字符（换行符）
        cout << "按 Enter 键继续..." << endl;
        cin.get();
        system("clear");
    }
    else
    {
        cout << "输入有误！" << endl;
    }
}

// 将数据保存到文件中
void WorkerManager::save()
{

    // 创建文件写入流
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    // 写入文件
    for (int i = 0; i < this->m_count; i++)
    {
        ofs << left << setw(10) << this->m_employees[i]->m_no << left
            << setw(20) << this->m_employees[i]->m_name << left << setw(10)
            << this->m_employees[i]->m_dept_no << endl;
    }
    // 关闭文件流
    ofs.close();
}

// 显示员工
void WorkerManager::show_employees()
{

    if (this->is_file_empty)
    {
        cout << "文件不存在或文件内容为空！" << endl;
    }
    else
    {
        // 1. 读取文件: 在构造函数中已经读取文件了

        // 2. 显示
        for (int i = 0; i < this->m_count; i++)
        {
            // 此处调用 showInfo() 体现类多态
            this->m_employees[i]->showInfo();
        }
    }
    cout << "按任意键继续..." << endl;
    cin.ignore(); // 忽略一个字符（换行符）
    cin.get();
    system("clear");
}

// 统计文件中的员工人数
int WorkerManager::get_emp_count()
{
    ifstream ifs;
    int _count = 0;
    ifs.open(FILENAME, ios::in); // 打开文件
    int _no, _deptNo;
    string _name;
    while (ifs >> _no && ifs >> _name && ifs >> _deptNo)
    {
        _count++;
    }
    return _count;
}

// 初始化员工
void WorkerManager::init_employees()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int _no, _deptNo;
    string _name;

    int index = 0;
    while (ifs >> _no && ifs >> _name && ifs >> _deptNo)
    {
        Worker *worker = NULL;

        // 根据不同的部门 No 创建不同的对象
        if (_deptNo == 1)
        {
            worker = new Employee(_no, _name, _deptNo);
        }
        else if (_deptNo == 2)
        {
            worker = new Manager(_no, _name, _deptNo);
        }
        else if (_deptNo == 3)
        {
            worker = new Boss(_no, _name, _deptNo);
        }

        // 将对象存储到数组中
        this->m_employees[index++] = worker;
    }
}

// 删除员工
void WorkerManager::delete_employee()
{
    // 判断文件是否存在
    if (this->is_file_empty)
    {
        cout << "文件不存在或者文件为空！" << endl;
    }
    else
    {
        // 根据用户输入删除指定的员工
        cout << "请输入想要删除的员工编号：";
        int _del_no;
        cin >> _del_no;

        // 判断 _del_no 是否存在
        int idx = this->is_exists(_del_no);
        if (idx != -1)
        {
            // 存在可以删除：移动数组元素，并且重新写入到文件
            // 循环遍历，找到后移动
            for (int i = idx + 1; i < this->m_count; i++)
            {
                this->m_employees[i - 1] = this->m_employees[i];
            }
            // 总数据量减一
            this->m_count--;
            // 重新写入到文件
            this->save();
            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "输入的员工编号错误！" << endl;
        }
        cout << "按 Enter 键继续..." << endl;
        cin.get();
        cin.get();
    }
}

// 按照员工编号 _no 查询员工是否存在
int WorkerManager::is_exists(int _no)
{
    int idx = -1;
    for (int i = 0; i < this->m_count; i++)
    {
        if (this->m_employees[i]->m_no == _no)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

// 修改员工信息
void WorkerManager::modify_employee()
{
    // 判断文件是否存在
    if (!this->is_file_empty)
    {
        int _no;
        cout << "请输入要修改的员工编号：";
        cin >> _no;
        // 文件存在
        // 根据 _no 获取的员工在数组中的索引
        int idx = this->is_exists(_no);
        if (idx != -1)
        {

            cout << "已经查询到编号为：" << _no << "的员工，请输入要修改的内容：" << endl;
            // 找到 _no 了, 根据 idx 修改对应的员工信息
            // 提示请输入 no、name、和 deptNo
            string _empName;
            int _deptNo, _newNo;
            cout << "请输入新的员工编号：";
            cin >> _newNo;
            cout << "请输入员工姓名：";
            cin >> _empName;
            cout << "请输入岗位：" << endl;
            cout << "1、普通员工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> _deptNo;

            this->m_employees[idx]->m_no = _newNo;
            this->m_employees[idx]->m_name = _empName;
            this->m_employees[idx]->m_dept_no = _deptNo;

            this->save();
            cout << "修改完毕！" << endl;
            cout << "按 Enter 键结束..." << endl;
            cin.ignore(); // 忽略一个字符（换行符）
            cin.get();
            system("clear");
        }
        else
        {
            cout << "输入的 员工编号 无效!" << endl;
        }
    }
    else
    {
        cout << "文件不存在或者文件为空!" << endl;
    }
}

// 查找员工
void WorkerManager::find_employee()
{
    if (this->is_file_empty)
    {
        cout << "文件不存在或文件为空！" << endl;
    }
    else
    {
        // 查找文件中的内容
        cout << "请输入查找方式：1、按员工编号查找 2、按员工姓名查找" << endl;
        int selected;
        cin >> selected;
        if (selected == 1)
        {
            // 按员工编号查找
            int _no;
            cout << "请输入员工编号：";
            cin >> _no;

            int idx = this->is_exists(_no);
            if (idx != -1)
            {
                // 找到了对应的员工
                cout << "找到了该职工，该职工信息如下：" << endl;
                this->m_employees[idx]->showInfo();
            }
            else
            {
                cout << "未查询到该职工！" << endl;
            }
        }
        else if (selected == 2)
        {
            string _emp_name;
            // 按员工姓名查找
            cout << "请输入要查找的员工姓名：";
            cin >> _emp_name;

            // 是否查找到了
            bool flag = false;
            for (int i = 0; i < this->m_count; i++)
            {
                if (this->m_employees[i]->m_name == _emp_name)
                {
                    cout << "查找成功，职工编号为：" << this->m_employees[i]->m_no
                         << "具体信息如下：" << endl;
                    flag = true;
                    this->m_employees[i]->showInfo();
                }
            }
            if (!flag)
            {
                cout << "查找失败，没有找到名字叫：" << _emp_name << "的人！" << endl;
            }
        }
        else
        {
            cout << "输入有误， 请重新输入！" << endl;
        }
        cout << "按 Enter 键继续..." << endl;
        cin.ignore();
        cin.get();
    }
}

// 排序：用户可以指定排序规则
void WorkerManager::sort_employees()
{

    if (this->is_file_empty)
    {
        cout << "文件不存在或者文件为空!" << endl;
        cout << "按任意键继续..." << endl;
        cin.ignore();
        cin.get();
        system("clear");
    }
    else
    {
        cout << "请选择排序方式：" << endl;
        cout << "1、按职工编号升序排序" << endl;
        cout << "2、按职工编号降序排序" << endl;

        int selected = 0;
        cin >> selected;

        // 通过选择排序进行
        for (int i = 0; i < this->m_count; i++)
        {
            // 用一个变量来记录最大值或者最小值的下标
            int min_or_max_index = i;

            for (int j = i + 1; j < this->m_count; j++)
            {
                // 判断是升序还是降序
                if (selected == 1)
                {
                    // 升序排序
                    if (this->m_employees[min_or_max_index]->m_no > this->m_employees[j]->m_no)
                    {
                        // 更新下标
                        min_or_max_index = j;
                    }
                }
                else
                {
                    // 降序排序
                    if (this->m_employees[min_or_max_index]->m_no < this->m_employees[j]->m_no)
                    {
                        min_or_max_index = j;
                    }
                }
            }

            // 判断是否要重新覆盖 min_or_max_index
            if (i != min_or_max_index)
            {
                // 交换
                Worker *temp = this->m_employees[min_or_max_index];
                this->m_employees[min_or_max_index] = this->m_employees[i];
                this->m_employees[i] = temp;
            }
        }

        // 将排序后的结果保存到文件中
        this->save();
        cout << "排序成功， 排序后的结果为：" << endl;
        this->show_employees();
    }
}