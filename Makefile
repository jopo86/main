all:
	g++ -g --std=c++17 -Iinclude -Llib  src/*.cpp src/*.c -lglfw3dll -o main