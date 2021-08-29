# -*- MakeFile -*-

all:
	g++ src/*.cpp -I. -Iinclude -Iinclude/SDL2 -lSDL2main -lSDL2 -o build/app
	./build/app