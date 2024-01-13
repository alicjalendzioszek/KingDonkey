#pragma once
#include "struktury.h"
#include "Zegar.h"

class Przeciwnik
{
public:
	XY pozycja;
	XY rozmiar;

	XY predkosc;
	Zegar zegar;

	bool zwroconyWPrawo = false;

	void zaaktualizujPozycje();
};

