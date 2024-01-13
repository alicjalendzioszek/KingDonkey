#pragma once
#include "struktury.h"

class BabyKrowa
{
public:
	XY pozycja;
	XY rozmiar;
	const double przesuniecieZderzenia = 1.0;
	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();
};

