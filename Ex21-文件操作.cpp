#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 1. 写文本文件
void writeTextFile()
{
    // 创建文件流
    ofstream ofs;

    // 指定打开方式
    ofs.open("test.txt", ios::out);

    // 向文件中写入内容
    ofs << "it is a test, 这是一个文本文件的写入测试。" << endl;
    ofs << "姓名：steve，赵晓虎" << endl;
    ofs << "性别：male，男" << endl;

    // 关闭文件
    ofs.close();
}

// 2. 读文本文件
string readTextFile()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    // 判断文件是否打开成功
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl;
    }
    else
    {
        cout << "文件打开成功！" << endl;
    }

    // // 第一种读取方式：
    // // 声明一个用来存储数据的变量
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }

    // // 第二种读取方式
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }

    // // 第三种读取方式
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }

    // 第四种
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }

    // 关闭文件
    ifs.close();
    return "ok";
}

int main()
{
    // writeTextFile();
    readTextFile();
    return 0;
}