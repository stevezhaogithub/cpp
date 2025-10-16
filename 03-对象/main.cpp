//
//  main.cpp
//  03-对象
//
//  Created by steve xiaohu zhao on 2025/9/28.
//

#include <iostream>

class Player {
  public:
    int x, y;
    int speed;

    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }
};

int main(int argc, const char *argv[]) {
    Player player;
    player.x = 5;
    player.y = 109;
    player.speed = 100;
    
    player.Move(10, 20);

    return 0;
}
