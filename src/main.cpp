#include "Renderer.h"

Renderer* pen;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

float angle;

SDL_Event event;

bool isRunning = false;

RES size;

float scale;
float theta;

Point points3D[8] = {
					{0,0,0},{100,0,0},{100,100,0},{0,100,0},{0,0,100},{100,0,100},{100,100,100},{0,100,100}
				  };

Point* rotated[8];

Point* transformed[8];

// int rotationX[3][3];
// int rotationY[3][3];
// int rotationZ[3][3]

int transfrom[2][3] = {{1,0,0},{0,1,0}};

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

	float rotationX[3][3] = 	{
							{1,0,0},
							{0,cos(angle),-sin(angle)},
							{0,sin(angle),cos(angle)}	
						};   

	float rotationY[3][3] = 	{
							{cos(angle),0,sin(angle)},
							{0,1,0},
							{-sin(angle),0,cos(angle)}	
						};

	float rotationZ[3][3] = 	{
							{cos(angle),-sin(angle),0},
							{sin(angle),cos(angle),0},
							{0,0,1}	
						};

	for(int i = 0; i < 8; i++)
	{
		//rotate here for example lets rotate cube z axis
		transformed[i] = matmul_return2D(transfrom,points3D[i]);
		rotated[i] = matmul_return3D(rotationZ, *transformed[i]);
	}
	angle+=0.0001;
}

void render()
{
	//display simpleWindow
	pen->setColour(0, 0, 0);
	pen->drawBackGround();
	pen->setColour(255,255,255);
	
	pen->join(*rotated[0],*rotated[1]);
	pen->join(*rotated[1],*rotated[2]);
	pen->join(*rotated[2],*rotated[3]);
	pen->join(*rotated[3],*rotated[0]);
	pen->join(*rotated[4],*rotated[5]);
	pen->join(*rotated[5],*rotated[6]);
	pen->join(*rotated[6],*rotated[7]);
	pen->join(*rotated[7],*rotated[4]);

	pen->join(*rotated[0],*rotated[4]);
	pen->join(*rotated[1],*rotated[5]);
	pen->join(*rotated[2],*rotated[6]);
	pen->join(*rotated[3],*rotated[7]);

	pen->present();

	for(int i = 0; i < 8; i++)
	{
		delete rotated[i];
		delete transformed[i];
	}
}

int init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	size = getRES();
	pen = new Renderer("Lorenz Attractor", size);

	theta = 180;
	angle=0.0f;

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