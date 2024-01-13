#pragma once
#include "struktury.h"

class Drabina
{
public:
	XY pozycja;
	XY rozmiar;
	XY rozmiarPlatformyWKtorejJest;
	bool czyWPlatformie = false;

	DlugoscPlatformy dlugoscPlatformyWKtorejSieZnajduje;
	DlugoscDrabiny dlugosc;

	double przesuniecieZderzenia = 3.0;

	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();
};

