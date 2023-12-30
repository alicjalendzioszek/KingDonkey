#include "Okno.h"

Okno::Okno()
{
	czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	zielony = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	czerwony = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	niebieski = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
}

Okno::~Okno()
{
	// zwolnienie powierzchni / freeing all surfaces
	if (charset != nullptr) {
		SDL_FreeSurface(charset);
	}
	if (screen != nullptr) {
		SDL_FreeSurface(screen);
	}
	if (scrtex != nullptr) {
		SDL_DestroyTexture(scrtex);
	}
	if (window != nullptr) {
		SDL_DestroyWindow(window);
	}
	if (renderer != nullptr) {
		SDL_DestroyRenderer(renderer);
	}
}

int Okno::inicjalizacjaSdl()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}

	// tryb pe³noekranowy / fullscreen mode
	//	rc = SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP,
	//	                                 &window, &renderer);
	int rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0,
		&window, &renderer);
	if (rc != 0) {
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		return 1;
	};

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetWindowTitle(window, "Szablon do zdania drugiego 2017");


	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
		0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		SCREEN_WIDTH, SCREEN_HEIGHT);


	// wy³¹czenie widocznoœci kursora myszy
	SDL_ShowCursor(SDL_DISABLE);

	// wczytanie obrazka cs8x8.bmp

	charset = SDL_LoadBMP("./cs8x8.bmp");
	if (charset == NULL) {
		printf("SDL_LoadBMP(cs8x8.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(charset, true, 0x000000);

	wczytajBitmapy();
}

int Okno::wczytajBitmapy()
{
	// graczSurface->w // szerkosc
	// graczSurface->h // wysokos

	graczSurface = SDL_LoadBMP("./bitmaps/krowa.bmp");
	if (graczSurface == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};

	graczRuch1Surface = SDL_LoadBMP("./bitmaps/krowa2.bmp");
	if (graczSurface == NULL) {
		printf("SDL_LoadBMP(krowa2.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};

	graczRuch2Surface = SDL_LoadBMP("./bitmaps/krowa3.bmp");
	if (graczSurface == NULL) {
		printf("SDL_LoadBMP(krowa3.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	
	graczSkokSurface = SDL_LoadBMP("./bitmaps/krowaJump.bmp");
	if (graczSurface == NULL) {
		printf("SDL_LoadBMP(krowaJump.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};







	beczkaSurface = SDL_LoadBMP("./bitmaps/belaaaa.bmp");
	if (beczkaSurface == NULL) {
		printf("SDL_LoadBMP(belaaaa.bmp) error: %s\n", SDL_GetError());

		SDL_Quit();
		return 1;
	};


	platformaSurface = SDL_LoadBMP("./bitmaps/platforma.bmp");
	if (platformaSurface == NULL) {
		printf("SDL_LoadBMP(platforma.bmp) error: %s\n", SDL_GetError());

		SDL_Quit();
		return 1;
	};
}

void Okno::narysujRamke(double worldTime, double fps)
{
	char text[128];
	// tekst informacyjny
	DrawRectangle(screen, 4, 4, SCREEN_WIDTH - 8, 36, czerwony, niebieski);
	sprintf_s(text, "Szablon drugiego zadania, czas trwania = %.1lf s  %.0lf klatek / s", worldTime, fps);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
	sprintf_s(text, "Esc - wyjscie, \030 - przyspieszenie, \031 - zwolnienie");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text, charset);
}

void Okno::wyczyscEkran()
{
	SDL_FillRect(screen, NULL, czarny);
}

void Okno::narysujSwiat(World& world)
{
	wyczyscEkran();
	narysujRamke(0, 0);//todo
	narysujPlansze(world);
	narysujGracza(world.gracz);
	zaaktualizujEkran();
}

void Okno::zaaktualizujEkran()
{
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Okno::narysujPlansze(World& world)
{
	for (int i = 0; i < world.liczbaBeczek; i++) {
		if (world.beczki[i].czyAktywna == true) {
			narysujBeczke(world.beczki[i]);
		}
	}

	for (int i = 0; i < world.liczbaPlatform; i++) {
		narysujRampe(world.platformy[i]);
	}
}

void Okno::narysujGracza(Gracz& gracz)
{
	if (gracz.numerKlatki == 0) {
		DrawSurface(screen, graczSurface, gracz.pozycja.x, gracz.pozycja.y);
	}
	// else if itp...
}

void Okno::narysujBeczke(Beczka& beczka)
{
	DrawSurface(screen, beczkaSurface, beczka.pozycja.x, beczka.pozycja.y);
}

void Okno::narysujRampe(Platforma& platforma)
{
	DrawSurface(screen, platformaSurface, platforma.pozycja.x, platforma.pozycja.y);
}
