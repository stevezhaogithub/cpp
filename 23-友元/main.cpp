//
//  main.cpp
//  23-友元
//
//  Created by steve xiaohu zhao on 2025/10/10.
//

#include <iostream>
using namespace std;

class House {

    // 友元函数（将全局函数的声明放到类中）
    friend void func(House *_house);

  public:
    // 构造函数
    House() {
        m_livingRoom = "客厅";
        m_bedRoom = "卧室";
    }

    // 客厅
    string m_livingRoom;

  private:
    // 卧室
    string m_bedRoom;
};

// 全局函数
void func(House *_house) {
    // 访问
    cout << "func 函数正在访问：" << _house->m_livingRoom << endl;
    cout << "func 函数正在访问：" << _house->m_bedRoom << endl;
}

void test01() {
    House h;
    func(&h);
}

int main(int argc, const char *argv[]) {
    test01();
    return 0;
}
