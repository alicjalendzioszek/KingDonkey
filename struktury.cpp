#include "struktury.h"

void aktualizacjaPozycji(XY& pozycja, XY& predkosc, double czas) {
	pozycja.x = pozycja.x + (predkosc.x * czas);
	pozycja.y = pozycja.y + (predkosc.y * czas);
}

bool czyKolizja(XY& pozycja1, XY& pozycja2) {

	// todo

	return false;
}