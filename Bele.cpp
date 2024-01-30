#include "Bele.h"

void Bele::setPozycja(double x, double y)
{
	this->pozycja.x = x;
	this->pozycja.y = y;
}

void Bele::setRozmiar(double x, double y)
{
	this->rozmiar.x = x;
	this->rozmiar.y = y;
}

XY Bele::getPozycja()
{
	return pozycja;
}
