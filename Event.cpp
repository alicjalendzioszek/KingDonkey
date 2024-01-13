#include "Event.h"
#include "Okno.h"

#include <iostream>

void Event::readEvents(World& world, Okno& okno)
{
	// obs³uga zdarzeñ (o ile jakieœ zasz³y) / handling of events (if there were any)

	while (SDL_PollEvent(&eventKlikniety)) {
		int keySymbol = eventKlikniety.key.keysym.sym;

		switch (eventKlikniety.type) {
		case SDL_KEYDOWN://todo zamienic czy na drabinie bo to dopiero ma potem byc sprawdzane
			if (keySymbol == SDLK_ESCAPE) okno.czyKoniec = true;
			else if (keySymbol == SDLK_w)
			{
				world.gracz.poruszaniePoDrabinieWgore = true;
				world.gracz.numerKlatkiPion++;
			}
			else if (keySymbol == SDLK_s)
			{
				world.gracz.poruszaniePoDrabinieWdol = true;
				world.gracz.numerKlatkiPion++;
			}
			else if (keySymbol == SDLK_a) { world.gracz.predkosc.x = -1.0 * world.gracz.predkoscRuchu; world.gracz.numerKlatkiPoziom++; world.gracz.czyRuchWPrawo = false; }
			else if (keySymbol == SDLK_d) { world.gracz.predkosc.x = world.gracz.predkoscRuchu; world.gracz.numerKlatkiPoziom++; world.gracz.czyRuchWPrawo = true; }
			else if (keySymbol == SDLK_SPACE)
			{
				/*if (world.gracz.czyAnimacjaSkoku == false)
				{
					world.gracz.czyAnimacjaSkoku = true;*/
				if (world.gracz.predkosc.y == 0) {


					world.gracz.czySkoczyl = true;
				}
				/*}*/

			}
			else if (keySymbol == SDLK_1) { world.poziom.numerPoziomu = 1; world.czyKoniecPoziomu = true; world.zegar.resetZegar(); }
			else if (keySymbol == SDLK_2) { world.poziom.numerPoziomu = 2; world.czyKoniecPoziomu = true; world.zegar.resetZegar(); }
			else if (keySymbol == SDLK_3) { world.poziom.numerPoziomu = 3; world.czyKoniecPoziomu = true; world.zegar.resetZegar(); }
			else if (keySymbol == SDLK_n) { world.czyKoniecPoziomu = true; world.gracz.numerKlatkiPion = 0; world.gracz.numerKlatkiPoziom = 0; world.zegar.resetZegar(); world.poziom.numerPoziomu = 1; world.gracz.liczbaPunktowGracza = 0; }
			break;
		case SDL_KEYUP:
			if (keySymbol == SDLK_a || keySymbol == SDLK_d) {
				world.gracz.predkosc.x = 0.0;
			}
			else if (keySymbol == SDLK_w) {
				world.gracz.poruszaniePoDrabinieWgore = false;
			}
			else if (keySymbol == SDLK_s) {
				world.gracz.poruszaniePoDrabinieWdol = false;
			}

			break;
		case SDL_QUIT:
			okno.czyKoniec = true;
			break;
		};
	};

}
