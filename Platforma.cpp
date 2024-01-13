#include "Platforma.h"

double Platforma::wezX1Zderzen()
{
	return this->pozycja.x - this->rozmiar.x;
}

double Platforma::wezX2Zderzen()
{
	return this->pozycja.x + this->rozmiar.x;
}

double Platforma::wezY1Zderzen()
{
	return this->pozycja.y - this->rozmiar.y;
}

double Platforma::wezY2Zderzen()
{
	return this->pozycja.y + this->rozmiar.y;
}