#pragma once
#include "struktury.h"

class Bele
{
private:
	XY pozycja;
	XY rozmiar;
public:
	//gettery
	XY getPozycja();

	//settery
	void setPozycja(double x,double y);
	void setRozmiar(double x,double y);

};

