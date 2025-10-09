//
//  Circle.hpp
//  14-点和圆的关系
//
//  Created by steve xiaohu zhao on 2025/10/9.
//

#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class Circle {
  private:
    int r;
    Point center;

  public:
    void setCenter(Point _center);
    Point getCenter();

    void setR(int _r);
    int getR();
};
