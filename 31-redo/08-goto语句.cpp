#include <iostream>

int main()
{

    // 下面是一个死循环的例子
FLAG:
    std::cout << "hello" << std::endl;
    goto FLAG;
}