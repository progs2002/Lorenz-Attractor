# -*- MakeFile -*-

all:
	g++ -g -Wall src/*.cpp -I. -I include -I include/SDL2 -lSDL2main -lSDL2 -o build/app
	./build/app
