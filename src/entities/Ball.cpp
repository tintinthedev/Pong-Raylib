#include "Ball.h"
#include "../globals/globals.h"
#include <raylib.h>

Ball::Ball(int x, int y, int speed_x, int speed_y, int radius, std::vector<Paddle*> colliders)
{
    this->x = x;
    this->y = y;
    this->speed_x = speed_x;
    this->speed_y = speed_y;
    this->radius = radius;
    this->colliders = colliders;
}

void Ball::Draw()
{
    DrawCircle(this->x, this->y, this->radius, Yellow);
}

void Ball::Update()
{
    this->x += this->speed_x;
    this->y += this->speed_y;

    this->CollisionCheck();
}

void Ball::CollisionCheck()
{
    if(this->y + this->radius >= GetScreenHeight() || this->y - this->radius <= 0)
      this->speed_y *= -1;

    for(Paddle* collider : this->colliders)
    {
        if(!CheckCollisionCircleRec(this->getCenter(), this->radius, collider->getCollisionRect()))
            continue;

        this->speed_x *= -1;
    }
}

Vector2 Ball::getCenter()
{
    return Vector2{(float)this->x, (float)this->y};
}

void Ball::reset()
{
    this->x = GetScreenWidth() / 2;
    this->y = GetScreenHeight() / 2;
}
