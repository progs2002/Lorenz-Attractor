#include "Renderer.h"

Renderer* pen;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

SDL_Event event;

bool isRunning = false;

RES size;

void update()
{
	//get delta time

	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentTick - lastTick) * 1000 / (double)SDL_GetPerformanceFrequency()); // in milliseconds
	
	//handle events

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
			break;
		}
	}
	
}

void render()
{
	//display simpleWindow
	pen->setColour(40, 52, 156);
	pen->drawBackGround();
	pen->present();
}

int init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	size = getRES();
	pen = new Renderer("Lorenz Attractor", size);

	isRunning = true;
	return 1;
}

int main(int argc, char* args[])
{
	init();

	while (isRunning)
	{
		update();
		render();
	}

	delete pen;

	return 0;
}