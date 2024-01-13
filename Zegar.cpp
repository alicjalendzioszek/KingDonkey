#include "Zegar.h"


Zegar::Zegar()
{

}


void Zegar::resetZegar()
{
	tick = SDL_GetTicks();
	frames = 0;
	delta = 0;
	worldTime = 0;
	fpsTimer = 0;
	fps = 0;
}

double Zegar::obliczDelte()
{
	double nowyTick = SDL_GetTicks();
	delta = (nowyTick - tick) * 0.001;
	tick = nowyTick;
	return delta;
}


double Zegar::podejrzyjDelteMS()
{
	double nowyTick = SDL_GetTicks();
	return (nowyTick - tick);
}

double Zegar::wezDelte()
{
	return delta;
}

double Zegar::wezWorldTime()
{
	return worldTime;
}

double Zegar::wezFps()
{
	return fps;
}

void Zegar::obliczCzasRozgrywki()
{
	obliczDelte();
	worldTime += delta;

	fpsTimer += delta;
	if (fpsTimer > 0.5) {
		fps = frames * 2;
		frames = 0;
		fpsTimer -= 0.5;
	};
}
