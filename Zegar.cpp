#include "Zegar.h"


Zegar::Zegar()
{
	start = SDL_GetTicks();
}

void Zegar::resetZegar()
{
	start = SDL_GetTicks();
}

double Zegar::obliczIleUplyneloOdStartu()
{
	tick = SDL_GetTicks();
	double delta = tick - start;
	return delta;
}

double Zegar::obliczDelte()
{
	double nowyTick = SDL_GetTicks();
	double delta = nowyTick - tick;
	tick = nowyTick;
	return delta;
}
