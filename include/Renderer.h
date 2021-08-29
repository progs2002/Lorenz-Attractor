#pragma once
#include "SDL.h"
#include "utils.h"

class Renderer
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Renderer(const char* title, RES size);
    ~Renderer();
    int drawBackGround();
	void setColour(int R, int G, int B);
	void present();
    void DrawCircle(int32_t centreX, int32_t centreY, int32_t radius);
};