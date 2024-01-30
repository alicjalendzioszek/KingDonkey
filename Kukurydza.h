#pragma once
#include "struktury.h"

class Kukurydza
{
private:
	XY pozycja;
	XY rozmiar;

	bool czyAktywna = true;
	const int liczbaPunktowKukurydza = 50;
	
public:
	
	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();

	//gettery
	XY getPozycja();
	XY getRozmiar();
	bool getCzyAktywna();
	int getLiczbaPunktowKukurydza();

	//settery
	void setPozycja(double x, double y);
	void setRozmiar(double x, double y);
	void setCzyAktywna(bool aktywnosc);
};

