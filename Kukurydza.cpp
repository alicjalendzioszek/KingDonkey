#include "Kukurydza.h"


double Kukurydza::wezX1Zderzen()
{
	return this->pozycja.x - this->rozmiar.x;
}

double Kukurydza::wezX2Zderzen()
{
	return this->pozycja.x + this->rozmiar.x ;
}

double Kukurydza::wezY1Zderzen()
{
	return this->pozycja.y - this->rozmiar.y ;
}

double Kukurydza::wezY2Zderzen()
{
	return this->pozycja.y + this->rozmiar.y ;
}