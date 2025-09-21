#include "Enemy.h"

Enemy::Enemy(int x, int y, int width, int height) : Paddle(x, y, width, height)
{
};

void Enemy::Update(Ball& ball)
{
    if(ball.y > this->y)
        this->y += this->speed;

    if(ball.y < this->y)
        this->y -= this->speed;

    Paddle::CollisionCheck();
}