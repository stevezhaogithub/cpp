/*
    1. 栈不能遍历
    - 栈不存在遍历的行为，因为只有栈顶元素才可以被访问到
    - 如果要访问每个元素的话，就需要让每个元素都出栈

    2. 栈可以获取到的一些数据
    - empty() 判断栈是否为空
    - size() 获取栈中元素个数

    3.
    - push()
    - pop()

    4. 栈的常用接口
    - 构造函数
    - 赋值操作
    - 存取数据
    - 大小操作

*/

#include <iostream>
#include <stack>
using namespace std;

void test01()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "栈大小：" << s.size() << endl;

    // 将栈中每个元素都出栈
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << "栈大小：" << s.size() << endl;
}
int main()
{
    test01();
    return 0;
}