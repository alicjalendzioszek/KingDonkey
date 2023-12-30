#include "Beczka.h"

void Beczka::zaaktualizujPozycje()
{
	auto delte = zegar.obliczDelte();
	aktualizacjaPozycji(pozycja, predkosc, delte);

	// czy pozycja koncowa 
}
