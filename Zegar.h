#pragma once

extern "C" {
#include "../SDL2-2.0.10/include/SDL.h"
#include "../SDL2-2.0.10/include/SDL_main.h"
}


class Zegar
{
public:

	Zegar();
	void obliczCzasRozgrywki();
	void resetZegar();
	double wezDelte();
	double wezWorldTime();
	double wezFps();
	double podejrzyjDelteMS();

private:
	double obliczDelte();
	
	double tick = 0;
	int  frames = 0;
	double delta = 0;	// czas jednej klatki
	double worldTime = 0;
	double fpsTimer = 0;
	double  fps = 0;

};