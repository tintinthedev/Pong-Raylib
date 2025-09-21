#include "Particle.h"

Particle::Particle(int x, int y, int width, int height, Color color, int speedX, int speedY)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
    this->speedX = speedX;
    this->speedY = speedY;
}

void Particle::Draw()
{
    DrawRectangle(this->x, this->y, this->width, this->height, this->color);
}

void Particle::Move()
{
    this->x += this->speedX;
    this->y += this->speedY;
}