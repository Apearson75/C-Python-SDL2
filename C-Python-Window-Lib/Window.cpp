#include "pch.h"
#include "Hello.h"
#include "Window.h"
#include <stdio.h>
#include <SDL.h>
#include <json.hpp>

SDL_Event* e;
using json = nlohmann::json;

void Window::Init()
{
	// Init
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Init(SDL_INIT_VIDEO);

	// Create Window & Renderer
	window = SDL_CreateWindow(
		"CWindow",
		this->x,
		this->y,
		this->width,
		this->height,
		this->flag
	);
	this->window = window;
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (window == NULL) {
		// In the case that the window could not be made...
		createMessageBox(L"Error", L"Window could not be created", MB_ICONSTOP);
		return;
	}
	else {

		// Change screenSurface
		this->screenSurface = SDL_GetWindowSurface(window);

		// White
		SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0xFF, 0xFF, 0xFF));

		SDL_UpdateWindowSurface(window);
	}
}

int Window::Loop()
{
	// Loop
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) return SDL_QUIT;
		return 0;
	}
}

void Window::Quit()
{
	SDL_DestroyWindow(this->window);

	SDL_Quit();
}

void Window::createRect(int x, int y, int w, int h, int r, int g, int b, int a)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

Window::Window(int x, int y, int width, int height, int flag)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->flag = flag;
}


// Exported to DLL
extern "C" {
	__declspec(dllexport)
	Window* newWindow(int x, int y, int width, int height, int flag) {
		return new Window(x, y, width, height, flag);
	}
	__declspec(dllexport)
	void windowInit(Window* window) {
		window->Init();
	}
	__declspec(dllexport)
	int windowLoop(Window* window) {
		return window->Loop();
	}
	__declspec(dllexport)
	void windowQuit(Window* window) {
		window->Quit();
	}
	__declspec(dllexport)
	void createRect(Window* window, int x, int y, int w, int h, int r, int g, int b, int a) {
		window->createRect(x, y, w, h, r, g, b, a);
	}
	__declspec(dllexport)
	SDL_Renderer* getRenderer(Window* window) {
		return window->renderer;
	}
}