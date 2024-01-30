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

XY Platforma::getPozycja()
{
	return pozycja;
}

XY Platforma::getRozmiar()
{
	return rozmiar;
}

DlugoscPlatformy Platforma::getDlugosc()
{
	return dlugosc;
}

void Platforma::setPozycja(double x, double y)
{
	this->pozycja.x = x;
	this->pozycja.y = y;
}

void Platforma::setRozmiar(double x, double y)
{
	this->rozmiar.x = x;
	this->rozmiar.y = y;
}

void Platforma::setDlugosc(DlugoscPlatformy dlugosc)
{
	this->dlugosc = dlugosc;
}
