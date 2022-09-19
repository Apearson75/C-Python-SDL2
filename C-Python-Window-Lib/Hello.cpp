#include "pch.h"
#include "Hello.h"
#include <SDL.h>

#include <stdio.h>
#include <Windows.h>

void hello()
{
	printf("Hello World");
}

int createMessageBox(LPCWSTR Ltitle, LPCWSTR Ldesc, int icon) {
	int msgBox = MessageBox(NULL, TEXT(desc), TEXT(title), MB_OKCANCEL | icon);

	return msgBox;
}

void createWindow(int x, int y, int width, int height, int flag) {
	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"CWindow",
		x,
		y,
		width,
		height,
		flag
	);

	if (window == NULL) {
		// In the case that the window could not be made...
		createMessageBox(L"Error", L"Window could not be created", MB_ICONSTOP);
		return;
	}

	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();
}