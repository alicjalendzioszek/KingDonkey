#pragma once
#include "struktury.h"

class Platforma {
private:
	XY pozycja;
	XY rozmiar;
	DlugoscPlatformy dlugosc;

	bool czyGraczZnajdujeSieNad;
	
public:
	
	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();

	XY getPozycja();
	XY getRozmiar();
	DlugoscPlatformy getDlugosc();
	
	void setPozycja(double x, double y);
	void setRozmiar(double x, double y);
	void setDlugosc(DlugoscPlatformy dlugosc);

};

