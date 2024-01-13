#include "Okno.h"

Okno::Okno()
{
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

	SDL_SetWindowTitle(window, "Alicja Lendzioszek, 193416 - King Donkey");


	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
		0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		SCREEN_WIDTH, SCREEN_HEIGHT);

	wczytajKolory();

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

void Okno::wczytajKolory()
{
	czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	zielony = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	czerwony = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	niebieski = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	fiolet = SDL_MapRGB(screen->format, 0x70, 0x40, 0xcc);
	jasnyNiebieski = SDL_MapRGB(screen->format, 0x20, 0x90, 0xff);
}

int Okno::wczytajBitmapy()
{
	
	kukurydzaSurface = SDL_LoadBMP("./bitmaps/kukurydza.bmp");
	if (kukurydzaSurface == NULL) {
		printf("SDL_LoadBMP(kukurydza.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(kukurydzaSurface, true, 0x000000);

	//gracz i jego animacje
	graczPrawo = SDL_LoadBMP("./bitmaps/krowaPrawy.bmp");
	if (graczPrawo == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczPrawo, true, 0x000000);

	graczRuch1Prawo = SDL_LoadBMP("./bitmaps/krowaPrawy2.bmp");
	if (graczRuch1Prawo == NULL) {
		printf("SDL_LoadBMP(krowa2.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczRuch1Prawo, true, 0x000000);

	graczRuch2Prawo = SDL_LoadBMP("./bitmaps/krowaPrawy3.bmp");
	if (graczRuch2Prawo == NULL) {
		printf("SDL_LoadBMP(krowa3.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczRuch2Prawo, true, 0x000000);

	graczSkokPrawo = SDL_LoadBMP("./bitmaps/krowaJumpPrawy.bmp");
	if (graczSkokPrawo == NULL) {
		printf("SDL_LoadBMP(krowaJump.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczSkokPrawo, true, 0x000000);

	graczLewo = SDL_LoadBMP("./bitmaps/krowa.bmp");
	if (graczLewo == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczLewo, true, 0x000000);

	graczRuch1Lewo = SDL_LoadBMP("./bitmaps/krowa2.bmp");
	if (graczRuch1Lewo == NULL) {
		printf("SDL_LoadBMP(krowa2.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};

	graczRuch2Lewo = SDL_LoadBMP("./bitmaps/krowa3.bmp");
	if (graczRuch2Lewo == NULL) {
		printf("SDL_LoadBMP(krowa3.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczRuch2Lewo, true, 0x000000);

	graczSkokLewo = SDL_LoadBMP("./bitmaps/krowaJump.bmp");
	if (graczSkokLewo == NULL) {
		printf("SDL_LoadBMP(krowaJump.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczSkokLewo, true, 0x000000);


	graczDrabina = SDL_LoadBMP("./bitmaps/krowaDrabina.bmp");
	if (graczDrabina == NULL) {
		printf("SDL_LoadBMP(krowaDrabina.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczDrabina, true, 0x000000);

	graczDrabina2 = SDL_LoadBMP("./bitmaps/krowaDrabina2.bmp");
	if (graczDrabina2 == NULL) {
		printf("SDL_LoadBMP(krowaDrabina2.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczDrabina2, true, 0x000000);

	graczDrabina3 = SDL_LoadBMP("./bitmaps/krowaDrabina3.bmp");
	if (graczDrabina3 == NULL) {
		printf("SDL_LoadBMP(krowaDrabina3.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(graczDrabina3, true, 0x000000);

	beczka1 = SDL_LoadBMP("./bitmaps/bela.bmp");
	if (beczka1 == NULL) {
		printf("SDL_LoadBMP(bela.bmp) error: %s\n", SDL_GetError());

		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(beczka1, true, 0x000000);

	beczka2 = SDL_LoadBMP("./bitmaps/bela2.bmp");
	if (beczka2 == NULL) {
		printf("SDL_LoadBMP(bela2.bmp) error: %s\n", SDL_GetError());

		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(beczka2, true, 0x000000);
	//przeciwnik
	przeciwnikPrawo = SDL_LoadBMP("./bitmaps/farmerPrawo.bmp");
	if (przeciwnikPrawo == NULL) {
		printf("SDL_LoadBMP(farmerPrawo.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(przeciwnikPrawo, true, 0x000000);

	przeciwnik2Prawo = SDL_LoadBMP("./bitmaps/farmer2Prawo.bmp");
	if (przeciwnik2Prawo == NULL) {
		printf("SDL_LoadBMP(farmer2Prawo.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(przeciwnik2Prawo, true, 0x000000);

	przeciwnik3Prawo = SDL_LoadBMP("./bitmaps/farmer3Prawo.bmp");
	if (przeciwnik3Prawo == NULL) {
		printf("SDL_LoadBMP(farmer3Prawo.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(przeciwnik3Prawo, true, 0x000000);

	przeciwnikLewo = SDL_LoadBMP("./bitmaps/farmerLewo.bmp");
	if (przeciwnikLewo == NULL) {
		printf("SDL_LoadBMP(farmerLewo.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(przeciwnikLewo, true, 0x000000);

	przeciwnik2Lewo = SDL_LoadBMP("./bitmaps/farmer2Lewo.bmp");
	if (przeciwnik2Lewo == NULL) {
		printf("SDL_LoadBMP(farmer2Lewo.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(przeciwnik2Lewo, true, 0x000000);

	przeciwnik3Lewo = SDL_LoadBMP("./bitmaps/farmer3Lewo.bmp");
	if (przeciwnik3Lewo == NULL) {
		printf("SDL_LoadBMP(farmerLewo.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(przeciwnik3Lewo, true, 0x000000);
	//platformy
	platformaNajkrotsza = SDL_LoadBMP("./bitmaps/platformaGigaKrotka.bmp");
	if (platformaNajkrotsza == NULL) {
		printf("SDL_LoadBMP(platformaGigaKrotka.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};

	platformaSrednia = SDL_LoadBMP("./bitmaps/platformaKrotka.bmp");
	if (platformaSrednia == NULL) {
		printf("SDL_LoadBMP(platformaKrotka.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};

	platformaNajdluzsza = SDL_LoadBMP("./bitmaps/platforma.bmp");
	if (platformaNajdluzsza == NULL) {
		printf("SDL_LoadBMP(platforma.bmp) error: %s\n", SDL_GetError());

		SDL_Quit();
		return 1;
	};

	//drabiny
	drabinaKrotka = SDL_LoadBMP("./bitmaps/drabinaShort.bmp");
	if (drabinaKrotka == NULL) {
		printf("SDL_LoadBMP(drabinaShort.bmp) error: %s\n", SDL_GetError());

		SDL_Quit();
		return 1;
	};

	drabinaDluga = SDL_LoadBMP("./bitmaps/drabinaLong.bmp");
	if (drabinaDluga == NULL) {
		printf("SDL_LoadBMP(drabinaLong.bmp) error: %s\n", SDL_GetError());

		SDL_Quit();
		return 1;
	};

	//stos bel
	stosBel = SDL_LoadBMP("./bitmaps/bele.bmp");
	if (stosBel == NULL) {
		printf("SDL_LoadBMP(bele.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(stosBel, true, 0x000000);
	//babyCow
	babyKrowaSurface = SDL_LoadBMP("./bitmaps/babyCow.bmp");
	if (babyKrowaSurface == NULL) {
		printf("SDL_LoadBMP(babyCow.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(babyKrowaSurface, true, 0x000000);
}

void Okno::narysujRamke(double worldTime, double fps)
{
	char text[128] = {};
	// tekst informacyjny
	DrawRectangle(screen, 350, 4, SCREEN_WIDTH - 700, 33, jasnyNiebieski, fiolet);
	sprintf_s(text, "Czas trwania poziomu = %.1lf s       1, 2, 3 - wybor poziomu         ZROBIONE: A,B,C,E", worldTime);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
	sprintf_s(text, "esc-wyjscie    n - nowa gra    w,a,s,d - poruszanie    spacja - skok");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 22, text, charset);

	


}

void Okno::narysujRamkeZWynikiem(World& world)//TODO
{
	char text[128] = {};
	int width = 180;
	int height = 33;
	int margin = 4;

	int x = SCREEN_WIDTH - width - margin;
	int y = margin;

	DrawRectangle(screen, x, y, width, height, jasnyNiebieski, fiolet);
	sprintf_s(text, "WYNIK: %.1ld ", world.gracz.liczbaPunktowGracza);
	DrawString(screen, (SCREEN_WIDTH-90) - strlen(text) * 8 / 2, 15, text, charset);
}

void Okno::wyczyscEkran()
{
	SDL_FillRect(screen, NULL, czarny);
}

void Okno::narysujSwiat(World& world)
{
	wyczyscEkran();
	world.zegar.obliczCzasRozgrywki();
	
	narysujPlansze(world);
	narysujGracza(world.gracz, world);
	/*for (int i = 0; i < world.liczbaBel; i++)
	{
		if (world.bele[i].czyAktywna)
		{

			narysujBeczke(world.bele[i], world.zegar.wezWorldTime());
		}
	}*/
	narysujBele(world.stosBel);
	narysujBabyKrowe(world.babyKrowa);
	narysujPrzeciwnika(world.przeciwnik, world.zegar.wezWorldTime());
	narysujRamke(world.zegar.wezWorldTime(), world.zegar.wezFps());//todo
	narysujRamkeZWynikiem(world);
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
	for (int i = 0; i < world.liczbaDrabin; i++) {
		narysujDrabine(world.drabiny[i]);
	}

	for (int i = 0; i < world.liczbaPlatform; i++) {
		narysujPlatforme(world.platformy[i]);
	}

	for (int i = 0; i < world.liczbaKukurydz; i++)
	{
		if (world.kukurydze[i].czyAktywna)
		{
			narysujKukurydze(world.kukurydze[i]);
		}
	}

	for (int i = 0; i < world.liczbaBel; i++) {
		if (world.bele[i].czyAktywna == true) {
			narysujBeczke(world.bele[i], world.zegar.wezWorldTime());
		}
	}
}

void Okno::narysujBabyKrowe(BabyKrowa& babyKrowa)
{
	DrawSurface(screen, babyKrowaSurface, babyKrowa.pozycja.x, babyKrowa.pozycja.y);
}

void Okno::narysujPrzeciwnika(Przeciwnik& przeciwnik, double worldTime)
{
	if ((int)worldTime % 6 == 0)
	{
		if (przeciwnik.zwroconyWPrawo)
		{
			DrawSurface(screen, przeciwnikPrawo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}
		else
		{
			DrawSurface(screen, przeciwnikLewo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}
	}
	else if ((int)worldTime % 6 == 1)
	{
		if (przeciwnik.zwroconyWPrawo)
		{
			DrawSurface(screen, przeciwnik2Prawo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}
		else
		{
			DrawSurface(screen, przeciwnik2Lewo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}
	}
	else if ((int)worldTime % 6 == 2)
	{
		if (przeciwnik.zwroconyWPrawo)
		{
			DrawSurface(screen, przeciwnik3Prawo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}
		else
		{
			DrawSurface(screen, przeciwnik3Lewo, przeciwnik.pozycja.x + 10, przeciwnik.pozycja.y);
		}
	}
	else if ((int)worldTime % 6 == 3)
	{
		if (przeciwnik.zwroconyWPrawo)
		{
			DrawSurface(screen, przeciwnik3Lewo, przeciwnik.pozycja.x - 5, przeciwnik.pozycja.y);
		}
		else
		{
			DrawSurface(screen, przeciwnik3Prawo, przeciwnik.pozycja.x + 10, przeciwnik.pozycja.y);
		}
	}
	else if ((int)worldTime % 6 == 4)
	{
		if (przeciwnik.zwroconyWPrawo)
		{
			DrawSurface(screen, przeciwnik2Lewo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}
		else
		{
			DrawSurface(screen, przeciwnik2Prawo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}

	}
	else if ((int)worldTime % 6 == 5)
	{
		if (przeciwnik.zwroconyWPrawo)
		{
			DrawSurface(screen, przeciwnikLewo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}
		else
		{
			DrawSurface(screen, przeciwnikPrawo, przeciwnik.pozycja.x, przeciwnik.pozycja.y);
		}
	}
}

void Okno::narysujGracza(Gracz& gracz, World& world)
{
	bool czyGraczSpada = gracz.predkosc.y > 0 && gracz.czyNaDrabinie == false;
	bool czyGraczLeci = gracz.predkosc.y < 0 && gracz.czyNaDrabinie == false;
	bool czySiePorusza = (gracz.czyNaDrabinie == false) && (gracz.predkosc.y == 0);
	bool czyNaDrabinie = gracz.czyNaDrabinie;

	world.ustalRozmiarGracza(*this);

	if (czySiePorusza) {
		if (gracz.numerKlatkiPoziom % 4 == 0) {
			if (gracz.czyRuchWPrawo == true)
			{
				DrawSurface(screen, graczPrawo, gracz.pozycja.x, gracz.pozycja.y);
			}
			else
			{
				DrawSurface(screen, graczLewo, gracz.pozycja.x, gracz.pozycja.y);
			}
		}
		else if (gracz.numerKlatkiPoziom % 4 == 1)
		{
			if (gracz.czyRuchWPrawo == true)
			{
				DrawSurface(screen, graczRuch1Prawo, gracz.pozycja.x, gracz.pozycja.y);
			}
			else
			{
				DrawSurface(screen, graczRuch1Lewo, gracz.pozycja.x, gracz.pozycja.y);
			}
		}
		else if (gracz.numerKlatkiPoziom % 4 == 2)
		{
			if (gracz.czyRuchWPrawo == true)
			{
				DrawSurface(screen, graczPrawo, gracz.pozycja.x, gracz.pozycja.y);
			}
			else
			{
				DrawSurface(screen, graczLewo, gracz.pozycja.x, gracz.pozycja.y);
			}
		}
		else if (gracz.numerKlatkiPoziom % 4 == 3)
		{
			if (gracz.czyRuchWPrawo == true)
			{
				DrawSurface(screen, graczRuch2Prawo, gracz.pozycja.x, gracz.pozycja.y);
			}
			else
			{
				DrawSurface(screen, graczRuch2Lewo, gracz.pozycja.x, gracz.pozycja.y);
			}
		}
		return;
	}

	if (czyNaDrabinie) {
		DrawSurface(screen, wezSurfaceDrabina(gracz.numerKlatkiPion), gracz.pozycja.x, gracz.pozycja.y);
		return;
	}

	if (czyGraczSpada || czyGraczLeci)
	{
		if (gracz.czyRuchWPrawo == true)
		{
			DrawSurface(screen, graczSkokPrawo, gracz.pozycja.x, gracz.pozycja.y);
		}
		else
		{
			DrawSurface(screen, graczSkokLewo, gracz.pozycja.x, gracz.pozycja.y);
		}
		return;
	}
	// else if itp...
}


void Okno::narysujBeczke(Beczka& beczka, double worldTime)
{
	/*double x=0;
	x = worldTime / 0.5;
	if (x == 0||x==0.1||x==0.2)
	{
		DrawSurface(screen, beczka1, beczka.pozycja.x, beczka.pozycja.y);
	}
	else
	{
		DrawSurface(screen, beczka2, beczka.pozycja.x, beczka.pozycja.y);

	}*/
	if ((int)worldTime % 2 == 0)
	{
		DrawSurface(screen, beczka1, beczka.pozycja.x, beczka.pozycja.y);
	}
	else
	{
		DrawSurface(screen, beczka2, beczka.pozycja.x, beczka.pozycja.y);
	}

}

void Okno::narysujPlatforme(Platforma& platforma)
{
	if (platforma.dlugosc == najdluzsza)
	{
		DrawSurface(screen, platformaNajdluzsza, platforma.pozycja.x, platforma.pozycja.y);
	}
	else if (platforma.dlugosc == srednia)
	{
		DrawSurface(screen, platformaSrednia, platforma.pozycja.x, platforma.pozycja.y);
	}
	else if (platforma.dlugosc == najkrotsza)
	{
		DrawSurface(screen, platformaNajkrotsza, platforma.pozycja.x, platforma.pozycja.y);
	}

}

void Okno::narysujDrabine(Drabina& drabina)
{
	if (drabina.dlugosc == krotka)
	{
		DrawSurface(screen, drabinaKrotka, drabina.pozycja.x, drabina.pozycja.y);
	}
	else if (drabina.dlugosc == dluga)
	{
		DrawSurface(screen, drabinaDluga, drabina.pozycja.x, drabina.pozycja.y);
	}
}

void Okno::narysujBele(Bele& bele)
{
	DrawSurface(screen, stosBel, bele.pozycja.x, bele.pozycja.y);
}

void Okno::narysujKukurydze(Kukurydza& kukurydza)
{
	DrawSurface(screen, kukurydzaSurface, kukurydza.pozycja.x, kukurydza.pozycja.y);
}

SDL_Surface* Okno::wezSurfaceDrabina(int numerKlatki)
{
	if (numerKlatki % 4 == 0)
	{
		return graczDrabina;
	}
	else if (numerKlatki % 4 == 1)
	{
		return graczDrabina2;
	}
	else if (numerKlatki % 4 == 2)
	{
		return graczDrabina;
	}
	else
	{
		return graczDrabina3;
	}

}
