#include "Drabina.h"

DlugoscDrabiny Drabina::getDlugoscDrabiny()
{
	return dlugosc;
}

XY Drabina::getPozycja()
{
	return pozycja;
}

DlugoscPlatformy Drabina::getDlugoscPlatformyWKtorejSieZnajduje()
{
	return dlugoscPlatformyWKtorejSieZnajduje;
}

double Drabina::getPrzesuniecieZderzenia()
{
	return przesuniecieZderzenia;
}

void Drabina::setPozycja(double x, double y)
{
	this->pozycja.x = x;
	this->pozycja.y = y;
}

void Drabina::setRozmiar(double x, double y)
{
	this->rozmiar.x = x;
	this->rozmiar.y = y;
}

void Drabina::setRozmiarPlatformyWKtorejJest(double x, double y)
{
	this->rozmiarPlatformyWKtorejJest.x = x;
	this->rozmiarPlatformyWKtorejJest.y = y;
}

void Drabina::setDlugosc(DlugoscDrabiny dlugosc)
{
	this->dlugosc = dlugosc;
}

void Drabina::setCzyWPlatformie(bool wPlatformie)
{
	this->czyWPlatformie = wPlatformie;
}

void Drabina::setDlugoscPlatformyWKtorejSieZnajduje(DlugoscPlatformy dlugosc)
{
	this->dlugoscPlatformyWKtorejSieZnajduje = dlugosc;
}

double Drabina::wezX1Zderzen()
{
	return this->pozycja.x - this->rozmiar.x + 3 * przesuniecieZderzenia;
}

double Drabina::wezX2Zderzen()
{
	return this->pozycja.x + this->rozmiar.x - 3 * przesuniecieZderzenia;
}

double Drabina::wezY1Zderzen()
{
	return this->pozycja.y - this->rozmiar.y - przesuniecieZderzenia;
}

double Drabina::wezY2Zderzen()
{
	return this->pozycja.y + this->rozmiar.y + przesuniecieZderzenia;
}