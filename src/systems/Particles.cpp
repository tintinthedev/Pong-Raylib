#include "Particles.h"
#include <ctime>
#include <thread>

void Particles::Draw()
{
    for(Particle* particle : this->activeParticles)
    {
        particle->Draw();
    }
}

void Particles::Update()
{
    for(Particle* particle : this->activeParticles)
    {
        particle->Move();
    }
}

void Particles::Emit(int quantity, Color color, Vector2 position)
{
    if(quantity < 0) return; 

    for(int i = 0; i < quantity; i++) 
    { 
        Particle* particle = new Particle(position.x, position.y, 6, 6, color, GetRandomValue(-10, 10), GetRandomValue(-10, 10)); 
        this->activeParticles.push_back(particle); 
    }
}