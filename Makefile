.PHONY: main
main:
	g++ -o main src/main.cpp src/globals/globals.cpp src/entities/Ball.cpp src/entities/Paddle.cpp src/entities/Enemy.cpp src/menu/Menu.cpp src/entities/Particle.cpp src/systems/Particles.cpp -l:libraylib.a -L:/usr/local/lib