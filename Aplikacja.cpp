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

			if (world.getCzyKoniecPoziomu()) {
				world.setCzyKoniecPoziomu(false);
				okno.setCzasRozpoczeciaAnimacjiDodawaniaPunktowBonus(0.0);
				okno.setCzasRozpoczeciaAnimacjiDodawaniaPunktowSkok(0.0);
				world.gracz.setCzyAnimacjaPunktowZaSkok(false);
				world.gracz.setCzyAnimacjaPunktowZaZebranieBonusa(false);
				world.setOstatniaAktywacjaBeczki(0);
				break;
			}

			if (okno.getCzyKoniec()||world.getCzyKoniecGry()) {
				return;
			}

			//world.czekaj();

		}
		world.zwalnianiePamieciDrabin();
		world.zwalnianiePamieciPlatform();
		world.zwalnianiePamieciBel();
		world.zwalnianiePamieciKukurydz();
		world.utworzSwiat(okno);
	}
}
