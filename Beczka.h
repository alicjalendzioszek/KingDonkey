#pragma once
#include "struktury.h"
#include "Zegar.h"

//KONIECZNIE TODO TO DO BO TO MUSI BYC TYLKO W OKNIE, NIE MOZE BYC TU DRUGI RAZ WIEC TRZEBA BEDZIE TO ZMIENIC!!!!!!!!!!!!!!
#define SCREEN_WIDTH	1400
#define SCREEN_HEIGHT	800

class Beczka
{
public:
	Zegar* zegar = nullptr;

	XY pozycja;
	XY pozycjaStartowa;

	XY rozmiar;
	XY predkosc;
	XY predkoscStart;
	bool czyAktywna = false;
	bool czySpada = false;
	const double przesuniecieZderzenia = 1.0;
	//const double podniesienieBeczki = -20.0;
	//int klatka = 0;
	int liczbaUpadkow = 0;
	bool czyMialMiejsceUpadek = false;
	bool czyZmienionoPredkosc = false;
	
	Beczka();

	//	void ustawPredkoscBeczkiX();
	const double poczatkowaPredkosc = -100;
	const double poczatkowaLiczbaUpadkow = 2;
	const double predkoscZmianyWSpadku = 700;
	void zaaktualizujPozycjeBeli(int numerPoziomu);

	void aktualizacjaPredkosciPoziom1();
	void aktualizacjaPredkosciPoziom2();
	void aktualizacjaPredkosciPoziom3();

	void resetujBeczke();

	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();

	void ustawZegar(Zegar* zegar);
};

