#pragma once

extern "C" {
#include "../SDL2-2.0.10/include/SDL.h"
#include "../SDL2-2.0.10/include/SDL_main.h"
}


class Zegar
{
public:
	double start = 0;
	double tick = 0;

	Zegar();

	void resetZegar();

	// w milisekundach
	double obliczIleUplyneloOdStartu();

	// w milisekundach
	double obliczDelte();
};