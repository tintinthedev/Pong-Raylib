#include "Paddle.h"
#include <raylib.h>

Paddle::Paddle(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Paddle::Draw()
{
    DrawRectangle(this->x, this->y, this->width, this->height, WHITE);
}

void Paddle::Update()
{
    if(IsKeyDown(KEY_UP))
        this->y -= this->speed;
    
    if(IsKeyDown(KEY_DOWN))
        this->y += this->speed;

    this->CollisionCheck();
}

void Paddle::CollisionCheck()
{
    if(this->y <= 0)
        this->y = 0;
    
    if(this->y + this->height >= GetScreenHeight())
        this->y = GetScreenHeight() - this->height;
}

Vector2 Paddle::getPos()
{
    return Vector2{(float)this->x, (float)this->y};
}

Rectangle Paddle::getCollisionRect()
{
    return Rectangle{(float)this->x, (float)this->y, (float)this->width, (float)this->height};
}