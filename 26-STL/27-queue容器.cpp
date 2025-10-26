
/*

Queue:
    队尾：进入
    队头：出去

    1. 队列也无法遍历

    2. 队列接口
    - empty()
    - size()
    - push()
    - pop()
    - back()
    - front()


*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Person
{
public:
    Person(string _name, int _age)
    {
        this->m_name = _name;
        this->m_age = _age;
    }
    string m_name;
    int m_age;
};

void test01()
{
    queue<Person> q;
    Person p1("1唐僧", 20);
    Person p2("2悟空", 10);
    Person p3("3沙僧", 200);
    Person p4("4八戒", 220);

    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << "队列大小：" << q.size() << endl;
    
    // 判断：只要队列不为空，出队
    while (!q.empty())
    {
        cout << "队头元素：" << "姓名：" << q.front().m_name << "， 年龄：" << q.front().m_age << endl;
        cout << "队头元素：" << "姓名：" << q.back().m_name << "， 年龄：" << q.back().m_age << endl;
        // 出队
        q.pop();
    }

    cout << "队列大小：" << q.size() << endl;
}

int main()
{
    test01();
    return 0;
}