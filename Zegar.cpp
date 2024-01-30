#include "Zegar.h"


Zegar::Zegar()
{

}


void Zegar::resetZegar()
{
	tick = SDL_GetTicks();
	delta = 0;
	worldTime = 0;
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

double Zegar::getDelta()
{
	return delta;
}

double Zegar::getWorldTime()
{
	return worldTime;
}

void Zegar::obliczCzasRozgrywki()
{
	obliczDelte();
	worldTime += delta;
}
