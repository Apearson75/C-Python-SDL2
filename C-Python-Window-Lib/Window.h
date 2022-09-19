#pragma once

#include <SDL.h>

class Window
{
public:
	int x;
	int y;
	int width;
	int height;
	int flag;
	SDL_Surface* screenSurface;
	SDL_Window* window;
	SDL_Renderer* renderer;

	Window(int x, int y, int width, int height, int flag);

	void Init();
	int Loop();
	void Quit();
	void createRect(int x, int y, int w, int h, int r, int g, int b, int a);
};
