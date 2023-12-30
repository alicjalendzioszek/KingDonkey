#pragma once
#include "funkcje.h"
#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480
#include "World.h"
class Platforma;
//pamietac zeby pozamieniac png na bitmapy
//upewnic sie czy musze robic swoje odbicia lustrzane czy wystraczy ze bede jakos w visualu je zamieniac
class Okno
{
public:
	int czarny;
	int zielony;
	int czerwony;
	int niebieski;
	//surface dla gracza + animacje
	SDL_Surface* graczSurface = nullptr;
	SDL_Surface* graczSkokSurface = nullptr;
	SDL_Surface* graczRuch1Surface = nullptr;
	SDL_Surface* graczRuch2Surface = nullptr;
	//surface dla przeciwnika + animacje
	SDL_Surface* przeciwnikSurface = nullptr;
	SDL_Surface* przeciwnik1Surface = nullptr;
	SDL_Surface* przeciwnik2Surface = nullptr;
	//surface dla beczki
	SDL_Surface* beczkaSurface = nullptr;
	//surface dla platformy
	SDL_Surface* platformaSurface = nullptr;
	//pozostale surface
	SDL_Surface* screen = nullptr;
	SDL_Surface* charset = nullptr;
	SDL_Texture* scrtex = nullptr;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	bool czyKoniec = false;

	Okno();
	~Okno();

	int inicjalizacjaSdl();

	int wczytajBitmapy();

	void narysujRamke(double worldTime, double fps);

	void wyczyscEkran();


	void narysujSwiat(World& world);


	void zaaktualizujEkran();

	void narysujPlansze(World& world);


	void narysujGracza(Gracz& gracz);

	void narysujBeczke(Beczka& beczka);

	void narysujRampe(Platforma& platforma);

};

