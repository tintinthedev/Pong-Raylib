#pragma once
#include <vector>
#include "../entities/Particle.h"

class Particles
{
public:
    void Update();

    void Draw();

    void Emit(int quantity, Color color, Vector2 position);

private:
    std::vector<Particle*> activeParticles;
};