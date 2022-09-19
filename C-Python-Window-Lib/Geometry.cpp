#include "pch.h"
#include "Geometry.h"
#include <iostream>
#include <SDL.h>

void Geometry::createRect(SDL_Renderer* renderer, int x, int y, int w, int h)
{
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &r);
	SDL_RenderPresent(renderer);
}

extern "C" {
	__declspec(dllexport)
	void createRect(SDL_Renderer* renderer, int x, int y, int w, int h) {
		std::cout << "A";
		Geometry::createRect(renderer, x, y, w, h);
	}
}