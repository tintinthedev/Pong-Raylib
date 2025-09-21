#pragma once
#include <raylib.h>

class Paddle
{
public:
    int x, y, width, height;

    Paddle(int x, int y, int width, int height);

    void Draw();

    void Update();

    Vector2 getPos();

    Rectangle getCollisionRect();

    int speed = 6;

private:

protected:
    void CollisionCheck();
};