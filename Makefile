.PHONY: main
main:
	g++ -o main src/main.cpp src/globals/globals.c src/entities/Ball.cpp src/entities/Paddle.cpp src/entities/Enemy.cpp src/menu/Menu.cpp -l:libraylib.a -L:/usr/local/lib