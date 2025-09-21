#pragma once
#include <raylib.h>

class Particle
{
    int x, y, width, height, speedX, speedY;
    Color color;
public:
    Particle(int x, int y, int width, int height, Color color, int speed, int speedY);

    void Draw();

    void Move();
};