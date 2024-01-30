#include "Okno.h"

bool Okno::getCzyKoniec()
{
	return czyKoniec;
}

void Okno::setCzyKoniec(bool koniec)
{
	this->czyKoniec = koniec;
}

void Okno::setCzasRozpoczeciaAnimacjiDodawaniaPunktowSkok(double czas)
{
	this->czasRozpoczeciaAnimacjiDodawaniaPunktowSkok = czas;
}

void Okno::setCzasRozpoczeciaAnimacjiDodawaniaPunktowBonus(double czas)
{
	this->czasRozpoczeciaAnimacjiDodawaniaPunktowBonus = czas;
}

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

	punktyZaSkok = SDL_LoadBMP("./bitmaps/300.bmp");
	if (punktyZaSkok == NULL) {
		printf("SDL_LoadBMP(300.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(punktyZaSkok, true, 0x000000);

	punktyZaZebranieBonusu = SDL_LoadBMP("./bitmaps/50.bmp");
	if (punktyZaZebranieBonusu == NULL) {
		printf("SDL_LoadBMP(50.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	};
	SDL_SetColorKey(punktyZaZebranieBonusu, true, 0x000000);

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

void Okno::narysujRamke(double worldTime)
{
	char text[128] = {};
	// tekst informacyjny
	DrawRectangle(screen, 350, 4, SCREEN_WIDTH - 700, 33, jasnyNiebieski, fiolet);
	sprintf_s(text, "Czas trwania poziomu = %.1lf s       1, 2, 3 - wybor poziomu        ZROBIONE: A,B,C,E,F", worldTime);
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
	sprintf_s(text, "WYNIK: %.1ld ", world.gracz.getLiczbaPunktowGracza());
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
	narysujGracza(world);
	narysujPunktyZaSkok(world);
	narysujPunktyZaZebranieBonusa(world);
	narysujBele(world.stosBel);
	narysujBabyKrowe(world.babyKrowa);
	narysujPrzeciwnika(world.przeciwnik, world.zegar.getWorldTime());
	narysujRamke(world.zegar.getWorldTime());
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
	for (int i = 0; i < world.getLiczbaDrabin(); i++) {
		narysujDrabine(world.getDrabiny()[i]);
	}

	for (int i = 0; i < world.getLiczbaPlatform(); i++) {
		narysujPlatforme(world.getPlatformy()[i]);
	}

	for (int i = 0; i < world.getLiczbaKukurydz(); i++)
	{
		if (world.getKukurydze()[i].getCzyAktywna())
		{
			narysujKukurydze(world.getKukurydze()[i]);
		}
	}

	for (int i = 0; i < world.getLiczbaBel(); i++) {
		if (world.getBele()[i].getAktywnosc() == true) {
			narysujBeczke(world.getBele()[i], world.zegar.getWorldTime());
		}
	}
}

void Okno::narysujBabyKrowe(BabyKrowa& babyKrowa)
{
	DrawSurface(screen, babyKrowaSurface, babyKrowa.getPozycja().x, babyKrowa.getPozycja().y);
}

void Okno::narysujPrzeciwnika(Przeciwnik& przeciwnik, double worldTime)
{
	if ((int)worldTime % 6 == 0)
	{
		if (przeciwnik.getZwroconyWPrawo())
		{
			DrawSurface(screen, przeciwnikPrawo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}
		else
		{
			DrawSurface(screen, przeciwnikLewo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}
	}
	else if ((int)worldTime % 6 == 1)
	{
		if (przeciwnik.getZwroconyWPrawo())
		{
			DrawSurface(screen, przeciwnik2Prawo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}
		else
		{
			DrawSurface(screen, przeciwnik2Lewo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}
	}
	else if ((int)worldTime % 6 == 2)
	{
		if (przeciwnik.getZwroconyWPrawo())
		{
			DrawSurface(screen, przeciwnik3Prawo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}
		else
		{
			DrawSurface(screen, przeciwnik3Lewo, przeciwnik.getPozycja().x + 10, przeciwnik.getPozycja().y);
		}
	}
	else if ((int)worldTime % 6 == 3)
	{
		if (przeciwnik.getZwroconyWPrawo())
		{
			DrawSurface(screen, przeciwnik3Lewo, przeciwnik.getPozycja().x - 5, przeciwnik.getPozycja().y);
		}
		else
		{
			DrawSurface(screen, przeciwnik3Prawo, przeciwnik.getPozycja().x + 10, przeciwnik.getPozycja().y);
		}
	}
	else if ((int)worldTime % 6 == 4)
	{
		if (przeciwnik.getZwroconyWPrawo())
		{
			DrawSurface(screen, przeciwnik2Lewo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}
		else
		{
			DrawSurface(screen, przeciwnik2Prawo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}

	}
	else if ((int)worldTime % 6 == 5)
	{
		if (przeciwnik.getZwroconyWPrawo())
		{
			DrawSurface(screen, przeciwnikLewo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}
		else
		{
			DrawSurface(screen, przeciwnikPrawo, przeciwnik.getPozycja().x, przeciwnik.getPozycja().y);
		}
	}
}

void Okno::narysujGracza(World& world)
{
	bool czyGraczSpada = world.gracz.getPredkosc().y > 0 && world.gracz.getCzyNaDrabinie() == false;
	bool czyGraczLeci = world.gracz.getPredkosc().y < 0 && world.gracz.getCzyNaDrabinie() == false;
	bool czySiePorusza = (world.gracz.getCzyNaDrabinie() == false) && (world.gracz.getPredkosc().y == 0);
	bool czyNaDrabinie = world.gracz.getCzyNaDrabinie();

	world.ustalRozmiarGracza(*this);

	if (czySiePorusza) {
		if (world.gracz.getNumerKlatkiPoziom() % 4 == 0) {
			if (world.gracz.getCzyRuchWPrawo())
			{
				DrawSurface(screen, graczPrawo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
			}
			else
			{
				DrawSurface(screen, graczLewo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
			}
		}
		else if (world.gracz.getNumerKlatkiPoziom() % 4 == 1)
		{
			if (world.gracz.getCzyRuchWPrawo())
			{
				DrawSurface(screen, graczRuch1Prawo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
			}
			else
			{
				DrawSurface(screen, graczRuch1Lewo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
			}
		}
		else if (world.gracz.getNumerKlatkiPoziom() % 4 == 2)
		{
			if (world.gracz.getCzyRuchWPrawo())
			{
				DrawSurface(screen, graczPrawo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
			}
			else
			{
				DrawSurface(screen, graczLewo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
			}
		}
		else if (world.gracz.getNumerKlatkiPoziom() % 4 == 3)
		{
			if (world.gracz.getCzyRuchWPrawo())
			{
				DrawSurface(screen, graczRuch2Prawo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
			}
			else
			{
				DrawSurface(screen, graczRuch2Lewo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
			}
		}
		return;
	}

	if (czyNaDrabinie) {
		DrawSurface(screen, wezSurfaceDrabina(world.gracz.getNumerKlatkiPion()), world.gracz.getPozycja().x, world.gracz.getPozycja().y);
		return;
	}

	if (czyGraczSpada || czyGraczLeci)
	{
		if (world.gracz.getCzyRuchWPrawo())
		{
			DrawSurface(screen, graczSkokPrawo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
		}
		else
		{
			DrawSurface(screen, graczSkokLewo, world.gracz.getPozycja().x, world.gracz.getPozycja().y);
		}
		return;
	}
}


void Okno::narysujBeczke(Beczka& beczka, double worldTime)
{
	if ((int)worldTime % 2 == 0)
	{
		DrawSurface(screen, beczka1, beczka.getPozycja().x, beczka.getPozycja().y);
	}
	else
	{
		DrawSurface(screen, beczka2, beczka.getPozycja().x, beczka.getPozycja().y);
	}
}

void Okno::narysujPlatforme(Platforma& platforma)
{
	if (platforma.getDlugosc() == najdluzsza)
	{
		DrawSurface(screen, platformaNajdluzsza, platforma.getPozycja().x, platforma.getPozycja().y);
	}
	else if (platforma.getDlugosc() == srednia)
	{
		DrawSurface(screen, platformaSrednia, platforma.getPozycja().x, platforma.getPozycja().y);
	}
	else if (platforma.getDlugosc() == najkrotsza)
	{
		DrawSurface(screen, platformaNajkrotsza, platforma.getPozycja().x, platforma.getPozycja().y);
	}

}

void Okno::narysujDrabine(Drabina& drabina)
{
	if (drabina.getDlugoscDrabiny() == krotka)
	{
		DrawSurface(screen, drabinaKrotka, drabina.getPozycja().x, drabina.getPozycja().y);
	}
	else if (drabina.getDlugoscDrabiny() == dluga)
	{
		DrawSurface(screen, drabinaDluga, drabina.getPozycja().x, drabina.getPozycja().y);
	}
}

void Okno::narysujBele(Bele& bele)
{
	DrawSurface(screen, stosBel, bele.getPozycja().x, bele.getPozycja().y);
}

void Okno::narysujKukurydze(Kukurydza& kukurydza)
{
	DrawSurface(screen, kukurydzaSurface, kukurydza.getPozycja().x, kukurydza.getPozycja().y);
}

void Okno::narysujPunktyZaSkok(World&world)
{
	bool naPlatformie = world.sprawdzCzyGraczStoiNaPlatformie();
	if (world.gracz.getCzyAnimacjaPunktowZaSkok() && naPlatformie)
	{
		if (world.gracz.getCzyAnimacjaPunktowZaZebranieBonusa())
		{
			world.gracz.setCzyAnimacjaPunktowZaZebranieBonusa(false);
			czasRozpoczeciaAnimacjiDodawaniaPunktowBonus = 0.0;
		}

		if (czasRozpoczeciaAnimacjiDodawaniaPunktowSkok == 0.0)
		{
			czasRozpoczeciaAnimacjiDodawaniaPunktowSkok = world.zegar.getWorldTime();
		}

		if (world.zegar.getWorldTime() - czasRozpoczeciaAnimacjiDodawaniaPunktowSkok >= czasTrwaniaAnimacjiDodawaniaPunktow)
		{
			world.gracz.setCzyAnimacjaPunktowZaSkok(false);
			czasRozpoczeciaAnimacjiDodawaniaPunktowSkok = 0.0;
		}
		else
		{
			DrawSurface(screen, punktyZaSkok, world.gracz.getPozycja().x, world.gracz.wezY1Zderzen() - 30);//magic number
		}
	}
	

}

void Okno::narysujPunktyZaZebranieBonusa(World&world)
{
	if (world.gracz.getCzyAnimacjaPunktowZaZebranieBonusa())
	{
		if (world.gracz.getCzyAnimacjaPunktowZaSkok())
		{
			world.gracz.setCzyAnimacjaPunktowZaSkok(false);
			czasRozpoczeciaAnimacjiDodawaniaPunktowSkok = 0.0;
		}

		if (czasRozpoczeciaAnimacjiDodawaniaPunktowBonus == 0.0)
		{
			czasRozpoczeciaAnimacjiDodawaniaPunktowBonus = world.zegar.getWorldTime();
		}

		if (world.zegar.getWorldTime() - czasRozpoczeciaAnimacjiDodawaniaPunktowBonus >= czasTrwaniaAnimacjiDodawaniaPunktow)
		{
			world.gracz.setCzyAnimacjaPunktowZaZebranieBonusa(false);
			czasRozpoczeciaAnimacjiDodawaniaPunktowBonus = 0.0;
		}
		else
		{
			DrawSurface(screen, punktyZaZebranieBonusu, world.gracz.getPozycja().x, world.gracz.wezY1Zderzen() - 30);//magic number
		}
	}
	
}


SDL_Surface* Okno::wezSurfaceDrabina(int numerKlatki)
{
	if (numerKlatki % 4 == 0 || numerKlatki % 4 == 2)
	{
		return graczDrabina;
	}
	else if (numerKlatki % 4 == 1)
	{
		return graczDrabina2;
	}
	else
	{
		return graczDrabina3;
	}

}
