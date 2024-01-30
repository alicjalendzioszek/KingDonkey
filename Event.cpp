#include "Event.h"
#include "Okno.h"


void Event::readEvents(World& world, Okno& okno)
{
	// obs³uga zdarzeñ (o ile jakieœ zasz³y)

	while (SDL_PollEvent(&eventKlikniety)) {
		int keySymbol = eventKlikniety.key.keysym.sym;

		switch (eventKlikniety.type) {
		case SDL_KEYDOWN:
			if (keySymbol == SDLK_ESCAPE) okno.setCzyKoniec(true);
			else if (keySymbol == SDLK_w)
			{
				world.gracz.setPoruszaniePoDrabinieWGore(true);
				world.gracz.zwiekszNumerKlatkiPion();
			}
			else if (keySymbol == SDLK_s)
			{
				world.gracz.setPoruszaniePoDrabinieWDol(true);
				world.gracz.zwiekszNumerKlatkiPion();
			}
			else if (keySymbol == SDLK_a) { world.gracz.setPredkoscX(-1.0 * world.gracz.getPredkoscRuchu());  world.gracz.zwiekszNumerKlatkiPoziom(); world.gracz.setCzyRuchWPrawo(false); }
			else if (keySymbol == SDLK_d) { world.gracz.setPredkoscX(world.gracz.getPredkoscRuchu()); world.gracz.zwiekszNumerKlatkiPoziom();  world.gracz.setCzyRuchWPrawo(true); }
			else if (keySymbol == SDLK_SPACE)
			{
				if (world.gracz.getPredkosc().y == 0) {
					world.gracz.setCzySkoczyl(true);
					world.gracz.setCzyDodanoPunktyZaSkok(false);
				}

			}
			else if (keySymbol == SDLK_1) { world.poziom.setNumerPoziomu(1); world.setCzyKoniecPoziomu(true); world.zegar.resetZegar(); world.setOstatniaAktywacjaBeczki(0); }
			else if (keySymbol == SDLK_2) { world.poziom.setNumerPoziomu(2); world.setCzyKoniecPoziomu(true); world.zegar.resetZegar(); world.setOstatniaAktywacjaBeczki(0); }
			else if (keySymbol == SDLK_3) { world.poziom.setNumerPoziomu(3); world.setCzyKoniecPoziomu(true); world.zegar.resetZegar(); world.setOstatniaAktywacjaBeczki(0); }
			else if (keySymbol == SDLK_n) { world.setCzyKoniecPoziomu(true); world.gracz.setNumerKlatkiPion(0); world.gracz.setNumerKlatkiPoziom(0); world.setOstatniaAktywacjaBeczki(0); world.zegar.resetZegar(); world.poziom.setNumerPoziomu(1); world.gracz.setLiczbaPunktowGracza(0); }
			break;
		case SDL_KEYUP:
			if (keySymbol == SDLK_a || keySymbol == SDLK_d) {
				world.gracz.setPredkoscX(0.0);
			}
			else if (keySymbol == SDLK_w) {
				world.gracz.setPoruszaniePoDrabinieWGore(false);
			}
			else if (keySymbol == SDLK_s) {
				world.gracz.setPoruszaniePoDrabinieWDol(false);
			}

			break;
		case SDL_QUIT:
			okno.setCzyKoniec(true);
			break;
		};
	};

}
