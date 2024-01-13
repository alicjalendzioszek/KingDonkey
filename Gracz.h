#pragma once
#include "struktury.h"
#include "Zegar.h"

class Gracz
{
public:

	Gracz();

	XY pozycja;
	XY pozycjaStartowa;
	XY predkosc;
	XY rozmiar;
	Zegar* zegar = nullptr;

	int liczbaPunktowGracza = 0;
	int numerKlatkiPion = 0;
	int numerKlatkiPoziom = 0;
	bool czySkoczyl = false;
	bool czySpada = false;
	bool czyNaDrabinie = false;
	bool czyRuchWPrawo = false;
	bool czyRuchDoDolu = false;
	bool czyAnimacjaSkoku = false;

	const double predkoscZmianyWSpadku = 700;
	const double predkoscSkoku = -400;
	const double predkoscRuchu = 200;
	const double predkoscPoDrabinie = 200;
	const double przesuniecieZderzenia = 1.0;

	void zaaktualizujPozycje();

	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();

	void ustawZegar(Zegar* zegar);

	bool poruszaniePoDrabinieWgore = false;
	bool poruszaniePoDrabinieWdol = false;

	void ustalPredkoscPoDrabinie();


};

