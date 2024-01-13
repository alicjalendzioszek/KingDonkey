#include "Aplikacja.h"

void Aplikacja::utworzAplikacje()
{
	okno.inicjalizacjaSdl();
	world.utworzSwiat(okno);
}

void Aplikacja::wystartujGre()
{
	while (true) {

		
		world.zegar.resetZegar();

		while (true) {	
			okno.narysujSwiat(world);
			world.wykonajTure(okno);

			if (world.czyKoniecPoziomu == true) {
				world.czyKoniecPoziomu = false;
				break;
			}

			if (okno.czyKoniec == true||world.czyKoniecGry==true) {
				return;
			}

			world.czekaj();

		}
		world.zwalnianiePamieciDrabin();
		world.zwalnianiePamieciPlatform();
		world.zwalnianiePamieciBel();
		world.zwalnianiePamieciKukurydz();
		world.utworzSwiat(okno);
		// przejdz do nowego etapu tj. stworz poziom na nowo kolejny poziom
		// a jak ktos wyjdzie

	}
}
