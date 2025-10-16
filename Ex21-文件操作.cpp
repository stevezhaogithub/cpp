#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Person
{
public:
    char name[64];
    int age;
};

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

// 3. 写入二进制文件
void writeBinaryFile()
{
    // 创建流对象
    ofstream ofs("person.bin", ios::out | ios::binary);
    // ofs.open("file01.bin", ios::out | ios::binary);
    Person p = {"张三", 19};
    ofs.write((const char *)&p, sizeof(p));
    ofs.close();
}

// 4. 读取二进制文件
void readBinaryFile()
{
    ifstream ifs("person.bin", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "file open failed." << endl;
    }
    Person p;
    ifs.read((char *)&p, sizeof(Person));

    cout << "姓名：" << p.name << endl;
    cout << "年龄：" << p.age << endl;
}

int main()
{
    // writeTextFile();
    // readTextFile();
    // writeBinaryFile();
    readBinaryFile();
    return 0;
}