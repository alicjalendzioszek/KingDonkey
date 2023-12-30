#include "Gracz.h"

void Gracz::zaaktualizujPozycje()
{
	auto delte = zegar.obliczDelte();


	if (czySpada) {
		predkosc.y = predkosc.y + (delte * predkoscZmianyWSpadku);
	}
	else {
		if (czySkoczyl) {
			predkosc.y = predkoscSkoku;
			czySkoczyl = false;
		}
	}

	aktualizacjaPozycji(pozycja, predkosc, delte);
}
