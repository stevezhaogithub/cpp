//
//  main.cpp
//  14-点和圆的关系
//
//  Created by steve xiaohu zhao on 2025/10/9.
//

#include <iostream>
#include <math.h>
using namespace std;

// 点类
class Point {
  private:
    // 坐标
    int x;
    int y;

  public:
    void setX(int _x) { x = _x; }
    int getX() { return x; }

    void setY(int _y) { y = _y; }
    int getY() { return y; }
};

// 圆类
class Circle {
  private:
    // 圆心
    Point center;
    // 半径
    int r;

  public:
    void setCenter(Point _center) { center = _center; }
    Point getCenter() { return center; }

    void setR(int _r) { r = _r; }
    int getR() { return r; }
};

// 判断点和圆之间的关系
void checkPointCircleRelation(Circle &c, Point &p) {
    // 计算圆心与点 p 之间的距离
    double dis = sqrt(
        (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY()));

    // 与半径 r 进行比较
    if (dis == c.getR()) {
        cout << "点在圆上。" << endl;
    } else if (dis > c.getR()) {
        cout << "点在圆外。" << endl;
    } else {
        cout << "点在圆内。" << endl;
    }
}

int main(int argc, const char *argv[]) {
    
    Circle c;
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);
    c.setR(10);
    
    Point p;
    p.setX(11);
    p.setY(91);
    
    checkPointCircleRelation(c, p);
    
    return 0;
}
