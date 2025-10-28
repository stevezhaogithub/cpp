#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
using namespace std;

// 员工
class Employee
{
public:
    string m_name;
    double m_salary;
};

// 输出员工信息
void print_vectors(const vector<Employee> &v)
{
    for (vector<Employee>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << "员工姓名：" << it->m_name << ", 工资：" << it->m_salary << endl;
    }
}

// 创建 10 名员工
void load_employees(vector<Employee> &v)
{
    string _nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Employee emp;
        // 此处不能使用 "员工-"+_nameSeed[i], 会认为是两个指针相加
        emp.m_name = string("员工-") + _nameSeed[i];
        emp.m_salary = rand() % 4001 + 6000; // [6000, 10000]
        v.push_back(emp);
    }
}

// 员工分组
void set_emp_group(vector<Employee> &v, multimap<int, Employee> &mp)
{
    // 假设一共有 3 个组：1人事部，2技术部，3销售部

    // 遍历每个员工，生成随机数，分配到不同的部门
    for (vector<Employee>::iterator it = v.begin(); it != v.end(); ++it)
    {
        // 生成一个随机数
        int dept_no = rand() % 3 + 1;
        mp.insert(make_pair(dept_no, *it));
    }
}

// 显示所有部门的所有员工
void print_multimap(const multimap<int, Employee> &mp)
{
    for (multimap<int, Employee>::const_iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << "员工部门: " << it->first << ", 员工姓名: " << it->second.m_name << ", 员工工资:" << it->second.m_salary << "元." << endl;
    }
}

// 按部门显示员工
void print_employees_by_group(const multimap<int, Employee> &mp)
{
    cout << "人事部:" << endl;
    multimap<int, Employee>::const_iterator it1 = mp.find(1);
    int _count = mp.count(1);
    for (int i = 0; it1 != mp.end() && i < _count; it1++, i++)
    {
        cout << "员工姓名: " << it1->second.m_name << ", 员工工资:" << it1->second.m_salary << "元." << endl;
    }
    cout << "------------------------" << endl;

    cout << "技术部:" << endl;
    multimap<int, Employee>::const_iterator it2 = mp.find(2);
    _count = mp.count(2);
    for (int i = 0; it2 != mp.end() && i < _count; it2++, i++)
    {
        cout << "员工姓名: " << it2->second.m_name << ", 员工工资:" << it2->second.m_salary << "元." << endl;
    }
    cout << "------------------------" << endl;

    cout << "技术部:" << endl;
    multimap<int, Employee>::const_iterator it3 = mp.find(3);
    _count = mp.count(3);
    for (int i = 0; it3 != mp.end() && i < _count; it3++, i++)
    {
        cout << "员工姓名: " << it3->second.m_name << ", 员工工资:" << it3->second.m_salary << "元." << endl;
    }
    cout << "------------------------" << endl;
}

int main()
{

    // 随机种子
    srand((unsigned int)time(NULL));

    // 1. 创建员工
    vector<Employee> v_employees;
    // 2. 加载员工信息
    load_employees(v_employees);

    // 3. 员工分组（分不同部门，每个部门可以有多个员工）multimap
    multimap<int, Employee> emp_map;
    set_emp_group(v_employees, emp_map);

    // 按部门输出员工信息
    print_employees_by_group(emp_map);
    // 遍历分组信息
    // print_multimap(emp_map);

    // 输出员工信息
    // print_vectors(v_employees);
    return 0;
}