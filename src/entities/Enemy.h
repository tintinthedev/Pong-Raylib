#pragma once
#include "Paddle.h"
#include "Ball.h"

class Enemy : public Paddle
{
public:
    Enemy(int x, int y, int width, int height);

    void Update(Ball& ball);
};