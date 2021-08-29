#include "Renderer.h"

Renderer::Renderer(const char* title, RES size)
{
	window = SDL_CreateWindow(title , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.W, size.H, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "deleted window and renderer" << std::endl;
}

int Renderer::drawBackGround()
{
	SDL_RenderClear(renderer);
	return 1;
}

void Renderer::setColour(int R, int G, int B)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, SDL_ALPHA_OPAQUE);
}

void Renderer::present()
{
	SDL_RenderPresent(renderer);
}

void Renderer::showAxis()
{
	SDL_RenderDrawLine(renderer, 0, 400, 800, 400);
	SDL_RenderDrawLine(renderer, 400, 0, 400, 800);
}

void Renderer::plot(float(*func)(float))
{

	float dx = 1;

	for(float i = -400.0f; i <= 400.0f; i+=dx)
	{
		//SDL_RenderDrawPoint(renderer, i + 400, 400 - func(i));
		SDL_RenderDrawLine(renderer, i + 400, 400 - func(i), i + dx + 400, 400 - func(i + dx));
	}
}