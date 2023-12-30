#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<string.h>

#include "funkcje.h"

extern "C" {
#include "../SDL2-2.0.10/include/SDL.h"
#include "../SDL2-2.0.10/include/SDL_main.h"
}

#define SCREEN_WIDTH	1400
#define SCREEN_HEIGHT	800

// main
#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char** argv) {
	int t1, t2, quit, frames, rc;
	double delta, worldTime, fpsTimer, fps, distance, distanceKrowa, etiSpeed, krowaSpeed;
	SDL_Event event;
	SDL_Surface* screen, * charset;
	SDL_Surface* platforma;
	SDL_Surface* platformaGigaKrotka;
	SDL_Surface* przeciwnik1;
	SDL_Surface* przeciwnik2;
	SDL_Surface* przeciwnik3;
	SDL_Surface* bele;
	SDL_Surface* babyCow;
	SDL_Surface* platformaKrotka;
	SDL_Surface* drabinaLong;
	SDL_Surface* drabinaShort;
	SDL_Surface* krowa;
	SDL_Surface* krowaSkok;
	SDL_Surface* krowaTylem1;
	SDL_Surface* krowaTylem2;
	SDL_Surface* krowaTylem11;
	SDL_Surface* krowaPrawy;
	SDL_Surface* krowa2;
	SDL_Surface* krowaPrawy2;
	SDL_Surface* krowa3;
	SDL_Surface* krowaPrawy3;
	SDL_Texture* scrtex;
	SDL_Window* window;
	SDL_Renderer* renderer;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}

	// tryb pe³noekranowy / fullscreen mode
//	rc = SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP,
//	                                 &window, &renderer);
	rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0,
		&window, &renderer);
	if (rc != 0) {
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		return 1;
	};

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetWindowTitle(window, "Szablon do zdania drugiego 2024");


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

	platforma = SDL_LoadBMP("./bitmaps/platforma.bmp");
	if (platforma == NULL) {
		printf("SDL_LoadBMP(eti.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	bele = SDL_LoadBMP("./bitmaps/beleBmp.bmp");
	if (bele == NULL) {
		printf("SDL_LoadBMP(eti.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	przeciwnik3 = SDL_LoadBMP("./bitmaps/farmerEND3bmpLeft.bmp");
	if (przeciwnik3 == NULL) {
		printf("SDL_LoadBMP(farmerEND3bmpLeft.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	platformaGigaKrotka = SDL_LoadBMP("./bitmaps/platformaGigaKrotka.bmp");
	if (platformaGigaKrotka == NULL) {
		printf("SDL_LoadBMP(platformaGigaKrotka.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};


	przeciwnik2 = SDL_LoadBMP("./bitmaps/farmerEND4Bmp.bmp");
	if (przeciwnik2 == NULL) {
		printf("SDL_LoadBMP(farmerEND4Bmp.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	przeciwnik1 = SDL_LoadBMP("./bitmaps/farmerEND1bmp2.bmp");
	if (przeciwnik1 == NULL) {
		printf("SDL_LoadBMP(farmerEND1bmp2.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};


	platformaKrotka = SDL_LoadBMP("./bitmaps/platformaKrotka.bmp");
	if (platformaKrotka == NULL) {
		printf("SDL_LoadBMP(platformaKrotka.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};


	drabinaLong = SDL_LoadBMP("./bitmaps/drabinaLong.bmp");
	if (drabinaLong == NULL) {
		printf("SDL_LoadBMP(drabina.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	drabinaShort = SDL_LoadBMP("./bitmaps/drabinaShort.bmp");
	if (drabinaShort == NULL) {
		printf("SDL_LoadBMP(drabina.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	krowa = SDL_LoadBMP("./bitmaps/krowa.bmp");
	if (krowa == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};


	krowaSkok = SDL_LoadBMP("./bitmaps/krowaJump.bmp");
	if (krowaSkok == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};


	krowaTylem1 = SDL_LoadBMP("./bitmaps/krowaTylem1.bmp");
	if (krowaTylem1 == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	krowaTylem2 = SDL_LoadBMP("./bitmaps/krowaTylem2.bmp");
	if (krowaTylem2 == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	krowaTylem11 = SDL_LoadBMP("./bitmaps/krowaTylem11.bmp");
	if (krowaTylem11 == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	krowaPrawy = SDL_LoadBMP("./bitmaps/krowaPrawy.bmp");
	if (krowaPrawy == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	krowa2 = SDL_LoadBMP("./bitmaps/krowa2.bmp");
	if (krowa2 == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	krowaPrawy2 = SDL_LoadBMP("./bitmaps/krowaPrawy2.bmp");
	if (krowaPrawy2 == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	krowa3 = SDL_LoadBMP("./bitmaps/krowa3.bmp");
	if (krowa3 == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	krowaPrawy3 = SDL_LoadBMP("./bitmaps/krowaPrawy3.bmp");
	if (krowaPrawy3 == NULL) {
		printf("SDL_LoadBMP(krowa.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	babyCow = SDL_LoadBMP("./bitmaps/babyCow.bmp");
	if (babyCow == NULL) {
		printf("SDL_LoadBMP(babyCow.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 1;
	};

	char text[128];
	int czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	int zielony = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	int czerwony = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	int niebieski = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);

	t1 = SDL_GetTicks();

	frames = 0;
	fpsTimer = 0;
	fps = 0;
	quit = 0;
	worldTime = 0;
	distance = 0;
	distanceKrowa = 0;
	etiSpeed = 0;
	krowaSpeed = 0;
	double distanceOld = 0;
	int distanceJump = 10;
	int liczba = 0;
	int liczbaY = 0;
	int reszta = 0;
	int resztaY = 0;
	bool czyOdwracac = false;
	bool czyX = true;
	bool czyY = false;
	bool czySkok = false;
	while (!quit) {
		t2 = SDL_GetTicks();

		// w tym momencie t2-t1 to czas w milisekundach,
		// jaki uplyna³ od ostatniego narysowania ekranu
		// delta to ten sam czas w sekundach
		// here t2-t1 is the time in milliseconds since
		// the last screen was drawn
		// delta is the same time in seconds
		delta = (t2 - t1) * 0.001;
		t1 = t2;

		worldTime += delta;

		distance += etiSpeed * delta;
		distanceKrowa += krowaSpeed * delta;

		SDL_FillRect(screen, NULL, czarny);

		//poziom1
		/*DrawSurface(screen, drabinaLong, 370, 680);
		DrawSurface(screen, drabinaLong, 1130, 680);
		DrawSurface(screen, drabinaShort, 600, 540);
		DrawSurface(screen, drabinaLong, 430, 380);
		DrawSurface(screen, drabinaLong, 1000, 380);
		DrawSurface(screen, drabinaLong, 880, 218);
		DrawSurface(screen, platforma, 700, 770);
		DrawSurface(screen, platforma, 820, 600);
		DrawSurface(screen, platforma, 600, 500);
		DrawSurface(screen, platforma, 870, 300);
		DrawSurface(screen, przeciwnik2, 1150, 220);
		DrawSurface(screen, bele, 1300, 215);
		DrawSurface(screen, platformaKrotka, 1050, 130);
		DrawSurface(screen, babyCow, 1200,96);*/

		////poziom2
		//DrawSurface(screen, platformaGigaKrotka, 700, 770);
		//DrawSurface(screen, drabinaShort, 777, 720);
		//DrawSurface(screen, drabinaShort, 623, 720);
		//DrawSurface(screen, drabinaShort, 932, 620);
		//DrawSurface(screen, drabinaShort, 468, 620);
		//DrawSurface(screen, drabinaShort, 313, 520);
		//DrawSurface(screen, drabinaShort, 313, 420);
		//DrawSurface(screen, drabinaShort, 1087, 520);
		//DrawSurface(screen, drabinaShort, 1087, 420);
		//DrawSurface(screen, drabinaShort, 933, 320);
		//DrawSurface(screen, drabinaShort, 468, 320);
		//DrawSurface(screen, platformaGigaKrotka, 855, 670);
		//DrawSurface(screen, platformaGigaKrotka, 855, 270);
		//DrawSurface(screen, platformaGigaKrotka, 545, 670);
		//DrawSurface(screen, platformaGigaKrotka, 545, 270);
		//DrawSurface(screen, platformaGigaKrotka, 700, 245);
		//DrawSurface(screen, platformaGigaKrotka, 390, 570);
		//DrawSurface(screen, platformaGigaKrotka, 390, 370);
		//DrawSurface(screen, platformaGigaKrotka, 1010, 570);
		//DrawSurface(screen, platformaGigaKrotka, 1010, 370);
		//DrawSurface(screen, platformaGigaKrotka, 1165, 470);
		//DrawSurface(screen, platformaGigaKrotka, 235, 470);
		//DrawSurface(screen, platformaKrotka, 440, 170);
		//DrawSurface(screen, platformaGigaKrotka, 780, 110);
		//DrawSurface(screen, babyCow, 830, 76);
		//DrawSurface(screen, przeciwnik3, 450, 98);
		//DrawSurface(screen, bele, 320, 93);
		
		//poziom3
		DrawSurface(screen, drabinaShort, 650, 145);
		DrawSurface(screen, drabinaShort, 340, 720);
		DrawSurface(screen, drabinaLong, 1020, 583);
		DrawSurface(screen, drabinaShort, 700, 428);
		DrawSurface(screen, drabinaLong, 350, 292);
		DrawSurface(screen, drabinaLong, 1020, 292);
		DrawSurface(screen, platformaKrotka, 320, 770);
		DrawSurface(screen, platformaKrotka, 510, 670);
		DrawSurface(screen, platformaKrotka, 1020, 670);
		DrawSurface(screen, platforma, 700, 503);
		DrawSurface(screen, platformaKrotka, 1200, 380);
		DrawSurface(screen, platformaKrotka, 700, 380);
		DrawSurface(screen, platformaKrotka, 200, 380);
		DrawSurface(screen, platforma, 550, 213);
		DrawSurface(screen, bele, 125, 127);
		DrawSurface(screen, przeciwnik3, 257, 133);
		DrawSurface(screen, platformaKrotka, 600, 95);
		DrawSurface(screen, babyCow, 500, 61);

		if (czySkok)
		{
			krowaSpeed = 0.1;
			distanceKrowa += krowaSpeed * delta;
			DrawSurface(screen, krowaSkok, 600 * distanceKrowa, 622 - distanceJump);

		}
		czySkok = false;
		if (czyY)
		{
			if (resztaY == 0)
			{

				DrawSurface(screen, krowaTylem1, 600, 622 * distanceKrowa);

			}
			else if (resztaY == 1)
			{

				DrawSurface(screen, krowaTylem2, 600, 622 * distanceKrowa);

			}
			else if (resztaY == 2)
			{

				DrawSurface(screen, krowaTylem11, 600, 622 * distanceKrowa);

			}
			else if (resztaY == 3)
			{
				DrawSurface(screen, krowaTylem2, 600, 622 * distanceKrowa);

			}
		}



		if (czyX)
		{
			if (reszta == 0)
			{
				if (czyOdwracac)
				{
					DrawSurface(screen, krowaPrawy, 600 * distanceKrowa, 622);
				}
				else
				{
					DrawSurface(screen, krowa, 600 * distanceKrowa, 622);
				}
			}
			else if (reszta == 1)
			{
				if (czyOdwracac)
				{
					DrawSurface(screen, krowaPrawy2, 600 * distanceKrowa, 622);
				}
				else
				{
					DrawSurface(screen, krowa2, 600 * distanceKrowa, 622);
				}
			}
			else if (reszta == 2)
			{
				if (czyOdwracac)
				{
					DrawSurface(screen, krowaPrawy, 600 * distanceKrowa, 622);
				}
				else
				{
					DrawSurface(screen, krowa, 600 * distanceKrowa, 622);
				}

			}
			else if (reszta == 3)
			{
				if (czyOdwracac)
				{
					DrawSurface(screen, krowaPrawy3, 600 * distanceKrowa, 622);
				}
				else
				{
					DrawSurface(screen, krowa3, 600 * distanceKrowa, 622);
				}

			}
		}



		//DrawSurface(screen, eti, SCREEN_WIDTH / 2 + sin(distance) * SCREEN_HEIGHT / 3, (SCREEN_HEIGHT / 2 + cos(distance) * SCREEN_HEIGHT / 3)-125);



		fpsTimer += delta;
		if (fpsTimer > 0.5) {
			fps = frames * 2;
			frames = 0;
			fpsTimer -= 0.5;
		};

		// tekst informacyjny / info text
		DrawRectangle(screen, 4, 4, SCREEN_WIDTH - 8, 36, czerwony, niebieski);
		//            "template for the second project, elapsed time = %.1lf s  %.0lf frames / s"
		sprintf_s(text, "Szablon drugiego zadania, czas trwania = %.1lf s  %.0lf klatek / s", worldTime, fps);
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
		//	      "Esc - exit"
		sprintf_s(text, "Esc - wyjscie, \030 - przyspieszenie, \031 - zwolnienie");
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text, charset);

		SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
		//		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, scrtex, NULL, NULL);
		SDL_RenderPresent(renderer);


		// obs³ugaa zdarzeñ (o ile jakieœ zasz³y) / handling of events (if there were any)
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
				else if (event.key.keysym.sym == SDLK_a)
				{
					czyY = false;
					czyX = true;
					czySkok = false;
					czyOdwracac = false;
					krowaSpeed = -0.5;
					distanceKrowa += krowaSpeed * delta;
					reszta = liczba % 4;
					liczba++;
				}
				else if (event.key.keysym.sym == SDLK_d)
				{
					czyX = true;
					czyY = false;
					czySkok = false;
					czyOdwracac = true;
					krowaSpeed = 0.5;
					distanceKrowa += krowaSpeed * delta;
					reszta = liczba % 4;
					liczba++;
				}
				else if (event.key.keysym.sym == SDLK_w)
				{
					czyX = false;
					czyY = true;
					czySkok = false;
					krowaSpeed = -0.3;
					distanceKrowa += krowaSpeed * delta;
					resztaY = liczbaY % 4;
					liczbaY++;
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					czyX = false;
					czyY = true;
					czySkok = false;
					krowaSpeed = 0.3;
					distanceKrowa += krowaSpeed * delta;
					resztaY = liczbaY % 4;
					liczbaY++;
				}
				else if (event.key.keysym.sym == SDLK_SPACE)
				{
					czyY = false;
					czyX = false;
					czyOdwracac = false;
					czySkok = true;

				}
				break;
			case SDL_KEYUP:
				krowaSpeed = 0.0;
				break;
			case SDL_QUIT:
				quit = 1;
				break;
			};
		};
		frames++;

	};
	// zwolnienie powierzchni
	SDL_FreeSurface(charset);
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
};
