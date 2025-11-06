#include "administrator.h"
// 默认的无参数构造函数
Administrator::Administrator()
{
}

// 有参数构造函数
Administrator::Administrator(string _name, string _pwd)
{
    this->m_name = _name;
    this->m_passwd = _pwd;
    // 初始化 v_stu 和 v_tea, 用来检测是否重复
    this->init_vector();
}

// 显示管理员菜单
void Administrator::show_menu()
{
    // 显示管理员菜单
    cout << "欢迎管理员: " << this->m_name << " 登录！" << endl;
    cout << "\t\t\t1. 添加账号" << endl;
    cout << "\t\t\t2. 查看账号" << endl;
    cout << "\t\t\t3. 查看机房" << endl;
    cout << "\t\t\t4. 清空预约" << endl;
    cout << "\t\t\t0. 注销登录" << endl;
    cout << "请选择您的操作: " << endl;
}

// 添加账号
void Administrator::add_account()
{

    // _fname: 文件操作要操作的文件名; _tip 根据不同角色，显示不同的提示语
    // _err_tips: 表示重复后的错误提示
    string _fname, _tip, _err_tips;
    ofstream ofs;

    int selected = 0;
    while (true)
    {
        cout << "请输入要添加的账号类型" << endl;
        cout << "1、添加学生" << endl;
        cout << "2、添加老师" << endl;

        cin >> selected;

        // 添加学生
        if (selected == 1)
        {
            _fname = STUDENT_FILE;
            _tip = "请输入学号: ";
            _err_tips = "学号重复, 请重新输入: ";
            break;
        }
        else if (selected == 2)
        {
            _fname = TEACHER_FILE;
            _tip = "请输入职工编号: ";
            _err_tips = "职工号重复, 请重新输入: ";
            break;
        }
        else
        {
            cout << "输入有误, 请重新输入!" << endl;
        }
    }

    // 写入流，并且是追加写入
    ofs.open(_fname, ios::out | ios::app);
    int _id;            // 学号 or 职工号
    string _name, _pwd; // 姓名 和 密码
    while (true)
    {
        cout << _tip << endl;
        cin >> _id;
        bool ret = this->check_repeat(_id, selected);
        if (ret)
        {
            cout << _err_tips << endl;
        }
        else
        {
            // 如果没有重复, 直接退出输入循环
            break;
        }
    }

    cout << "请输入姓名: " << endl;
    cin >> _name;
    cout << "请输入密码: " << endl;
    cin >> _pwd;

    // 向文件中写入数据
    ofs << _id << " " << _name << " " << _pwd << endl;
    ofs.close();
    cout << "添加记录成功！" << endl;

    // 重新加载一下文件中的数据到 vector 中
    this->init_vector();

    cin.ignore();
    cout << "按 Enter 键继续..." << endl;
    cin.get();
    system("clear");
}

// 查看机房信息
void Administrator::show_rooms()
{
}

// 清空预约
void Administrator::clear_reservations()
{
}
/**
 * 添加账号的时候判断是否有重复
 * 1. 初始化容器
 * 2. 学生容器
 * 3. 教师容器
 */
// 1. 初始化容器
void Administrator::init_vector()
{
    this->v_stu.clear();
    this->v_tea.clear();

    // 1. 读取学生文件
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "学生文件读取失败！" << endl;
        ifs.close();
        return;
    }
    Student s;
    while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_passwd)
    {
        this->v_stu.push_back(s);
    }
    cout << "当前的学生数量为: " << this->v_stu.size() << endl;
    ifs.close();

    // 2. 读取教师文件
    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "教师文件读取失败！" << endl;
        ifs.close();
        return;
    }
    Teacher t;
    while (ifs >> t.m_tid && ifs >> t.m_name && ifs >> t.m_passwd)
    {
        this->v_tea.push_back(t);
    }
    cout << "教师数量为: " << this->v_tea.size() << endl;
    ifs.close();
}

// 检测是否重复
bool Administrator::check_repeat(int _id, int _role)
{
    // 表示是学生角色
    if (_role == 1)
    {
        for (vector<Student>::iterator it = this->v_stu.begin(); it != this->v_stu.end(); ++it)
        {
            if (_id == it->m_id)
            {
                // 表示找到重复值了
                return true;
            }
        }
    }
    else if (_role == 2)
    {
        // 表示是教师角色
        for (vector<Teacher>::iterator it = this->v_tea.begin(); it != this->v_tea.end(); ++it)
        {
            if (_id == it->m_tid)
            {
                // 表示找到重复值了
                return true;
            }
        }
    }
    return false;
}

// 显示学生信息
void print_student(Student &s)
{
    cout << "学号: " << s.m_id << ", 姓名: " << s.m_name
         << ", 密码: " << s.m_passwd << endl;
}

// 显示教师信息
void print_teacher(Teacher &t)
{
    cout << "职工号: " << t.m_tid << ", 姓名: " << t.m_name
         << ", 密码: " << t.m_passwd << endl;
}

// 查看账号信息
void Administrator::show_accounts()
{
    cout << "选择要查看的内容: " << endl;
    cout << "1、查看所有学生: " << endl;
    cout << "2、查看所有教师: " << endl;

    int selected = 0;
    cin >> selected;

    if (selected == 1)
    {
        cout << "所有学生信息如下: " << endl;
        for_each(v_stu.begin(), v_stu.end(), print_student);
    }
    else if (selected == 2)
    {
        cout << "所有教师信息如下: " << endl;
        for_each(v_tea.begin(), v_tea.end(), print_teacher);
    }
    else
    {
        cout << "输入有误！" << endl;
    }

    cin.ignore(); // 因为前面有输入, 所以要添加这行代码
    cout << "按 Enter 键继续..." << endl;
    cin.get();
    system("clear");
}
