#include "Renderer.h"

Renderer* pen;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

float angle1,angle2,angle3;

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

int dx, dy, dz;

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

		if (event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_w:
					angle1+=0.1;
				break;
				case SDLK_s:
					angle1-=0.1;
				break;
				case SDLK_d:
					angle2+=0.1;
				break;
				case SDLK_a:
					angle2-=0.1;
				break;
				case SDLK_LEFT:
					angle3-=0.1;
				break;
				case SDLK_RIGHT:
					angle3+=0.1;

			}
		}
	}

	float rotationX[3][3] = 	{
							{1,0,0},
							{0,cos(angle1),-sin(angle1)},
							{0,sin(angle1),cos(angle1)}	
						};   

	float rotationY[3][3] = 	{
							{cos(angle2),0,sin(angle2)},
							{0,1,0},
							{-sin(angle2),0,cos(angle2)}	
						};

	float rotationZ[3][3] = 	{
							{cos(angle3),-sin(angle3),0},
							{sin(angle3),cos(angle3),0},
							{0,0,1}	
						};

	for(int i = 0; i < 8; i++)
	{
		//rotate here for example lets rotate cube z axis
		rotated[i] = matmul_return3D(rotationX, points3D[i]);
		rotated[i] = matmul_return3D(rotationY, *rotated[i]);
		rotated[i] = matmul_return3D(rotationZ, *rotated[i]);
		transformed[i] = matmul_return2D(transfrom,*rotated[i]);
	}
	
}

void render()
{
	//display simpleWindow
	pen->setColour(0, 0, 0);
	pen->drawBackGround();
	pen->setColour(255,255,255);
	
	pen->join(*transformed[0],*transformed[1]);
	pen->join(*transformed[1],*transformed[2]);
	pen->join(*transformed[2],*transformed[3]);
	pen->join(*transformed[3],*transformed[0]);
	pen->join(*transformed[4],*transformed[5]);
	pen->join(*transformed[5],*transformed[6]);
	pen->join(*transformed[6],*transformed[7]);
	pen->join(*transformed[7],*transformed[4]);

	pen->join(*transformed[0],*transformed[4]);
	pen->join(*transformed[1],*transformed[5]);
	pen->join(*transformed[2],*transformed[6]);
	pen->join(*transformed[3],*transformed[7]);

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
	angle1=0.0f;
	angle2=0.0f;
	angle3=0.0f;

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