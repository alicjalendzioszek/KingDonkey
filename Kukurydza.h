#pragma once
#include "struktury.h"

class Kukurydza
{
public:
	XY pozycja;
	XY rozmiar;
	const int liczbaPunktowKukurydza = 50;
	//const double przesuniecieZderzenia = 1.0;
	bool czyAktywna = true;


	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();
};

