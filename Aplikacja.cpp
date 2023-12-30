#include "Aplikacja.h"

void Aplikacja::utworzAplikacje()
{
	okno.inicjalizacjaSdl();
	world.utworzSwiat();
}

void Aplikacja::wystartujGre()
{
	while (true) {
		while (true) {
			okno.narysujSwiat(world);
			world.wykonajTure(okno);

			if (world.czyKoniecPoziomu == true) {
				break;
			}

			if (okno.czyKoniec == true) {
				return;
			}
		}
		// przejdz do nowego etapu tj. stworz poziom na nowo kolejny poziom
		// a jak ktos wyjdzie
	}
}
