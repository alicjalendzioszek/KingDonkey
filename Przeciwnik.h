#pragma once
#include "struktury.h"
#include "Zegar.h"

class Przeciwnik
{
private:
	XY pozycja;
	XY rozmiar;

	XY predkosc;
	Zegar zegar;

	bool zwroconyWPrawo = false;
public:

	XY getPozycja();
	bool getZwroconyWPrawo();

	void setPozycja(double x, double y);
	void setRozmiar(int x, int y);
	void setZwroconyWPrawo(bool czyWPrawo);

};

