#pragma once
#include "Paddle.h"
#include "../systems/Particles.h"
#include <vector>

class Ball
{
public:
    int x, y, speed_x, speed_y, radius;

    Ball(int x, int y, int speed_x, int speed_y, int radius, std::vector<Paddle*> colliders, Particles* particlesSystem);

    void Draw();

    void Update();

    Vector2 getCenter();

    void reset();

private:
    void CollisionCheck();
    std::vector<Paddle*> colliders;
    Particles* particlesSytem;
};