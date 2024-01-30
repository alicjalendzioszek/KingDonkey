#pragma once
#include "struktury.h"

void aktualizacjaPozycji(XY& pozycja, XY& predkosc, double czas) {
	pozycja.x = pozycja.x + (predkosc.x * czas);
	pozycja.y = pozycja.y + (predkosc.y * czas);
}