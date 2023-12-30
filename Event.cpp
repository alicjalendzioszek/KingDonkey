#include "Event.h"
#include "Okno.h"

void Event::readEvents(World& world, Okno& okno)
{
	// obs³uga zdarzeñ (o ile jakieœ zasz³y) / handling of events (if there were any)
	while (SDL_PollEvent(&eventKlikniety)) {
		switch (eventKlikniety.type) {
		case SDL_KEYDOWN:
			if (eventKlikniety.key.keysym.sym == SDLK_ESCAPE) okno.czyKoniec = true;
			else if (eventKlikniety.key.keysym.sym == SDLK_UP) world.gracz.predkosc.y = -100.0;
			else if (eventKlikniety.key.keysym.sym == SDLK_DOWN) world.gracz.predkosc.y = 100.0;
			else if (eventKlikniety.key.keysym.sym == SDLK_LEFT) world.gracz.predkosc.x = -100;
			else if (eventKlikniety.key.keysym.sym == SDLK_RIGHT) world.gracz.predkosc.x = 100;
			else if (eventKlikniety.key.keysym.sym = SDLK_SPACE) world.gracz.czySkoczyl = true;
			break;
		case SDL_KEYUP:
			world.gracz.predkosc.y = 0.0;
			world.gracz.predkosc.x = 0.0;
			break;
		case SDL_QUIT:
			okno.czyKoniec = true;
			break;
		};
	};
}
