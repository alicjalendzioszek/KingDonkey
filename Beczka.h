#pragma once
#include "struktury.h"
#include "Zegar.h"


class Beczka
{
public:
	XY pozycja;
	XY pozycjaKoncowa;
	XY pozycjaStartowa;

	XY rozmiar;
	XY predkosc;
	bool czyAktywna = false;
	Zegar zegar;

	void zaaktualizujPozycje();
};

