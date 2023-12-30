#pragma once
#include "struktury.h"
#include "Zegar.h"

class Gracz
{
public:
	XY pozycja;
	XY predkosc;
	XY rozmiar;
	Zegar zegar;

	int numerKlatki = 0;
	int liczbaPunktow = 0;
	bool czySkoczyl = false;
	bool czySpada = false;
	bool czyNaDrabinie = false;

	double predkoscZmianyWSpadku = 100;
	double predkoscSkoku = -100;

	void zaaktualizujPozycje();
};

