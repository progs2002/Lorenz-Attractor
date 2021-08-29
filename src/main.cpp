#include "Renderer.h"

Renderer* pen;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

SDL_Event event;

bool isRunning = false;

RES size;

float scale;
float theta;

void update()
{
	//handle events

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
			break;
		}

		if(event.type == SDL_MOUSEWHEEL)
		{
			if(event.wheel.y > 0)
				theta+=10;
			else if(event.wheel.y < 0)
				theta-=10;
		}

	}
	
	scale = abs(0.1 * theta);

	if(theta >= 1000.0f)
		theta = 1000.0f;

	if(theta <= 1.0f)
		theta = 1.0f;
}

void render()
{
	//display simpleWindow
	pen->setColour(0, 0, 0);
	pen->drawBackGround();
	pen->setColour(255,0,0);
	pen->showAxis();
	pen->setColour(255,255,255);
	pen->plot
	(
		[](float x)
		{
			x/=scale;

			//enter your function over here
			float y = sin(x);

			return scale * y;
		}
	);

	pen->present();
}

int init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	size = getRES();
	pen = new Renderer("Lorenz Attractor", size);

	theta = 180;

	isRunning = true;
	return 1;
}

int main(int argc, char* args[])
{
	init();

	while (isRunning)
	{
		lastTick = currentTick;
		currentTick = SDL_GetPerformanceCounter();
		deltaTime = (double)((currentTick - lastTick) * 1000 / (double)SDL_GetPerformanceFrequency()); // in milliseconds
		update();
		render();
		//std::cout << "time taken to update and render in milliseconds -> " << deltaTime << std::endl;
		std::cout << "theta = " << theta << std::endl;
	}

	delete pen;

	return 0;
}