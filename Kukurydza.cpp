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

XY Kukurydza::getPozycja()
{
	return pozycja;
}

XY Kukurydza::getRozmiar()
{
	return rozmiar;
}

bool Kukurydza::getCzyAktywna()
{
	return czyAktywna;
}

int Kukurydza::getLiczbaPunktowKukurydza()
{
	return liczbaPunktowKukurydza;
}

void Kukurydza::setPozycja(double x, double y)
{
	this->pozycja.x = x;
	this->pozycja.y = y;
}

void Kukurydza::setRozmiar(double x, double y)
{
	this->rozmiar.x = x;
	this->rozmiar.y = y;
}

void Kukurydza::setCzyAktywna(bool aktywnosc)
{
	this->czyAktywna = aktywnosc;
}
