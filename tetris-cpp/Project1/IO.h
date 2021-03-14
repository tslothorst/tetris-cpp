#pragma once

#define SDL_MAIN_HANDLED
#ifndef LINUX
#include "SDL.h"							
#include "sdl_gfxPrimitives.h"
#else
#include <SDL.h>									
#include "sdl_gfxprimitives.h"	
#endif
#pragma comment (lib, "SDL.lib")
#pragma comment (lib, "SDL_GfxPrimitives_Static.lib")

enum color { BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX }; // Colors

class IO
{
public:

	IO();

	void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);
	void ClearScreen();
	int GetScreenHeight();
	int InitGraph();
	int Pollkey();
	int Getkey();
	int IsKeyDown(int pKey);
	void UpdateScreen();
};

