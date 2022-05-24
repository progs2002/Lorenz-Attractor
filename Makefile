# -*- MakeFile -*-

all:
	@g++ src/*.cpp -g -Wall -I include -I include/SDL2 -o build/app -lSDL2main  -lSDL2

release: clean	
	@g++ src/*.cpp -O3 -Wall -I include -I include/SDL2 -o build/app -lSDL2main  -lSDL2

clean:
	@rm -f build/*