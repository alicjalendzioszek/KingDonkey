#pragma once

extern "C" {
#include "../SDL2-2.0.10/include/SDL.h"
#include "../SDL2-2.0.10/include/SDL_main.h"
}


class Zegar
{
private:
	double obliczDelte();

	double tick = 0;
	double delta = 0;	// czas jednej klatki
	double worldTime = 0;

public:

	Zegar();
	void obliczCzasRozgrywki();
	void resetZegar();
	double getDelta();
	double getWorldTime();
	double podejrzyjDelteMS();

};