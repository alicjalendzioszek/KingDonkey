#pragma once
#include "struktury.h"
#include "Zegar.h"
#include "wymiaryOkna.h"

class Beczka
{
private:

	XY pozycja;
	XY pozycjaStartowa;

	XY rozmiar;

	XY predkosc;
	XY predkoscStart;
	
	bool czyAktywna = false;
	bool czySpada = false;
	bool czyMialMiejsceUpadek = false;
	bool czyZmienionoPredkosc = false;

	int liczbaUpadkow = 0;
	const int liczbaPunktowZaPrzeskoczenie = 300;

	const double przesuniecieZderzenia = 1.0;
	const double przesunieciePrzeskoku = 100.0;
	const double poczatkowaPredkosc = -100;
	const double poczatkowaLiczbaUpadkow = 2;
	const double predkoscZmianyWSpadku = 700;

	Zegar* zegar = nullptr;
public:
	
	//gettery
	bool getAktywnosc();
	bool getCzySpada();
	bool getCzyMialMiejsceUpadek();
	int getLiczbaPunktowZaPrzeskoczenie();
	int getLiczbaUpadkow();
	double getPoczatkowaPredkosc();
	XY getRozmiar();
	XY getPozycja();

	//settery
	void setPredkoscX(double predkoscX);
	void setPredkoscY(double predkoscY);
	void setPredkoscStartX(double predkoscX);
	void setPozycjaY(double y);
	void setCzyZmienionoPredkosc(bool czyZmianaPredkosci);
	void setCzyMialMiejsceUpadek(bool czyMialMiejsceUpadek);
	void setPozycja(double x, double y);
	void setRozmiar(double x, double y);
	void setAktywnosc(bool aktywnosc);
	void setPozycjaStartowa(double x, double y);
	void setCzySpada(bool spadek);

	void zwiekszLiczbeUpadkow();
	
	Beczka();

	//funkcje
	void zaaktualizujPozycjeBeli(int numerPoziomu);

	void aktualizacjaPredkosciPoziom1();
	void aktualizacjaPredkosciPoziom2();
	void aktualizacjaPredkosciPoziom3();

	void resetujBeczke();

	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();

	double wezYPrzeskoku();

	void ustawZegar(Zegar* zegar);
};

