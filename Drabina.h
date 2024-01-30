#pragma once
#include "struktury.h"

class Drabina
{
private:
	XY pozycja;
	XY rozmiar;
	XY rozmiarPlatformyWKtorejJest;

	DlugoscPlatformy dlugoscPlatformyWKtorejSieZnajduje;
	DlugoscDrabiny dlugosc;

	bool czyWPlatformie = false;
	double przesuniecieZderzenia = 3.0;

public:
	
	//gettery
	DlugoscDrabiny getDlugoscDrabiny();
	XY getPozycja();
	DlugoscPlatformy getDlugoscPlatformyWKtorejSieZnajduje();
	double getPrzesuniecieZderzenia();

	//settery
	void setPozycja(double x, double y);
	void setRozmiar(double x, double y);
	void setRozmiarPlatformyWKtorejJest(double x, double y);
	void setDlugosc(DlugoscDrabiny dlugosc);
	void setCzyWPlatformie(bool wPlatformie);
	void setDlugoscPlatformyWKtorejSieZnajduje(DlugoscPlatformy dlugosc);

	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();
};

