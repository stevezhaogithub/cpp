//
//  main.cpp
//  13-立方体案例
//
//  Created by steve xiaohu zhao on 2025/10/9.
//

#include <iostream>
using namespace std;

// 立方体类
class Cube {
  private:
    // 长宽高
    int m_length; // 长
    int m_width;  // 宽
    int m_height; // 高
  public:
    void setLength(int _length) { m_length = _length; }
    int getLength() { return m_length; }

    void setWidth(int _width) { m_width = _width; }
    int getWidth() { return m_width; }

    void setHeight(int _height) { m_height = _height; }
    int getHeight() { return m_height; }
    // 计算面积
    int cal_area() {
        int s =
            2 * (m_length * m_width + m_width * m_height + m_length * m_height);
        return s;
    }

    // 计算体积
    int cal_volume() { return m_length * m_width * m_height; }

    // 判断是否与另一个立方体相等
    bool sameWith(Cube c) {
        if (getLength() == c.getLength() && getWidth() == c.getWidth() &&
            getHeight() == c.getHeight()) {
            return true;
        }
        return false;
    }
};

// 全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2) {
    // 长宽高都相等
    if (c1.getWidth() == c2.getWidth() && c1.getHeight() == c2.getHeight() &&
        c1.getLength() == c2.getLength()) {
        return true;
    }
    return false;
}

int main(int argc, const char *argv[]) {
    Cube c1;
    c1.setWidth(10);
    c1.setHeight(10);
    c1.setLength(10);

    cout << "面积：" << c1.cal_area() << " ---- " << "体积：" << c1.cal_volume()
         << endl;

    Cube c2;
    c2.setWidth(10);
    c2.setHeight(10);
    c2.setLength(10);

    bool b = isSame(c1, c2);
    // bool b = c1.sameWith(c2);
    
    cout << b << endl;
    return 0;
}
