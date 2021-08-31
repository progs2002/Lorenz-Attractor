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
std::vector<Point*> points;

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
	}

	points.push_back(new Point{rand() % size.W/2 * (int)pow(-1,rand()), rand() % size.H/2 * (int)pow(-1,rand())});

	SDL_Delay(100);

}

void render()
{
	//display simpleWindow
	pen->setColour(0, 0, 0);
	pen->drawBackGround();
	pen->setColour(255,255,255);
	pen->joinPoints(points);

	pen->present();
}

int init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	size = getRES();
	pen = new Renderer("Lorenz Attractor", size);

	theta = 180;

	srand(time(0));

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
		std::cout << "time taken to update and render in milliseconds -> " << deltaTime << std::endl;
		//std::cout << "theta = " << theta << std::endl;
	}

	delete pen;

	return 0;
}