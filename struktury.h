#pragma once
//#include "Gracz.h"
//#include "Beczka.h"
//class Gracz;
//class Beczka;

struct XY {
	double x = 0;
	double y = 0;
};

struct Predkosc {
	double x;
	double y;
};

enum DlugoscPlatformy
{
	najkrotsza,
	srednia,
	najdluzsza,
	brak
};

enum DlugoscDrabiny
{
	krotka,
	dluga
};

void aktualizacjaPozycji(XY& pozycja, XY& predkosc, double czas);


//bool czyKolizja(Gracz& gracz, Beczka& bela);