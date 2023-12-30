#pragma once


struct XY {
	double x = 0;
	double y = 0;
};

struct Predkosc {
	double x;
	double y;
};

void aktualizacjaPozycji(XY& pozycja, XY& predkosc, double czas);


bool czyKolizja(XY& pozycja1, XY& pozycja2);