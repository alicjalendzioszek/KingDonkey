#pragma once
#include "struktury.h"

class BabyKrowa
{
private:

	XY pozycja;
	XY rozmiar;
	const double przesuniecieZderzenia = 1.0;

public:

	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();

	//gettery
	XY getPozycja();

	//settery
	void setPozycja(int x, int y);
	void setRozmiar(int x, int y);
};

