//
//  Point.h
//  14-点和圆的关系
//
//  Created by steve xiaohu zhao on 2025/10/9.
//

#pragma once
#include <iostream>
using namespace std;

// Point 类的声明
class Point {
  private:
    int x;
    int y;

  public:
    void setX(int _x);
    int getX();

    void setY(int _y);
    int getY();
};
