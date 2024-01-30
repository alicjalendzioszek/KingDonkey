#include "Przeciwnik.h"

XY Przeciwnik::getPozycja()
{
	return pozycja;
}

bool Przeciwnik::getZwroconyWPrawo()
{
	return zwroconyWPrawo;
}

void Przeciwnik::setPozycja(double x, double y)
{
	this->pozycja.x = x;
	this->pozycja.y =y ;
}

void Przeciwnik::setRozmiar(int x, int y)
{
	this->rozmiar.x = x;
	this->rozmiar.y = y;
}

void Przeciwnik::setZwroconyWPrawo(bool czyWPrawo)
{
	this->zwroconyWPrawo = czyWPrawo;
}
