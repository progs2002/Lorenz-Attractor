#include "Renderer.h"

Renderer::Renderer(const char* title, RES size)
{
	this->size = size;
	window = SDL_CreateWindow(title , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.W, size.H, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "===========================" << std::endl;
	std::cout << "deleted window and renderer" << std::endl;
	std::cout << "===========================" << std::endl;
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
	SDL_RenderDrawLine(renderer, 0, size.H / 2, size.W, size.H / 2);
	SDL_RenderDrawLine(renderer, size.W / 2, 0, size.W / 2, size.H);
}

void Renderer::plot(float(*func)(float))
{

	float dx = 1;

	for(float i = -size.W/2; i <= size.W/2; i+=dx)
	{
		//SDL_RenderDrawPoint(renderer, i + 400, 400 - func(i));
		SDL_RenderDrawLine(renderer, i + size.W/2, size.H/2 - func(i), i + dx + size.W/2, size.H/2 - func(i + dx));
	}
}

void Renderer::joinPoints(std::vector<Point*>& points)
{
	if(points.size() > 1)
	{
		for(int i = 0; i < points.size() - 1; i++)
			SDL_RenderDrawLine(renderer, points.at(i)->x + size.W/2, size.H/2 - points.at(i)->y,points.at(i+1)->x + size.W/2, size.H/2 - points.at(i+1)->y);
	}
}

void Renderer::join(Point& p1, Point& p2)
{
	SDL_RenderDrawLine(renderer, p1.x + size.W/2, size.H/2 - p1.y, p2.x + size.W/2, size.H/2 - p2.y);
}