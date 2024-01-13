#pragma once
#include "funkcje.h"
#define SCREEN_WIDTH	1400
#define SCREEN_HEIGHT	800
#include "World.h"

class Platforma;
class Drabina;
class Bele;
class BabyKrowa;
class Kukurydza;
//pamietac zeby pozamieniac png na bitmapy
//upewnic sie czy musze robic swoje odbicia lustrzane czy wystraczy ze bede jakos w visualu je zamieniac
class Okno
{
public:
	int czarny;
	int zielony;
	int czerwony;
	int niebieski;
	int fiolet;
	int jasnyNiebieski;
	//surface dla gracza + animacje
	SDL_Surface* graczPrawo= nullptr;
	SDL_Surface* graczSkokPrawo= nullptr;
	SDL_Surface* graczRuch1Prawo= nullptr;
	SDL_Surface* graczRuch2Prawo= nullptr;
	SDL_Surface* graczLewo = nullptr;
	SDL_Surface* graczSkokLewo = nullptr;
	SDL_Surface* graczRuch1Lewo = nullptr;
	SDL_Surface* graczRuch2Lewo = nullptr;
	SDL_Surface* graczDrabina= nullptr;
	SDL_Surface* graczDrabina2= nullptr;
	SDL_Surface* graczDrabina3= nullptr;
	//surface dla babyKrowy
	SDL_Surface* babyKrowaSurface = nullptr;
	//surface dla przeciwnika + animacje
	SDL_Surface* przeciwnikPrawo= nullptr;
	SDL_Surface* przeciwnik2Prawo= nullptr;
	SDL_Surface* przeciwnik3Prawo= nullptr;
	SDL_Surface* przeciwnikLewo= nullptr;
	SDL_Surface* przeciwnik2Lewo= nullptr;
	SDL_Surface* przeciwnik3Lewo= nullptr;
	//surface dla beczki
	SDL_Surface* beczka1= nullptr;
	SDL_Surface* beczka2= nullptr;
	//surface dla platformy
	SDL_Surface* platformaNajkrotsza= nullptr;
	SDL_Surface* platformaSrednia= nullptr;
	SDL_Surface* platformaNajdluzsza= nullptr;
	//surface stosu bel
	SDL_Surface* stosBel = nullptr;
	//surface dla drabin
	SDL_Surface* drabinaKrotka= nullptr;
	SDL_Surface* drabinaDluga= nullptr;
	//kukurydza
	SDL_Surface* kukurydzaSurface = nullptr;
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
	void wczytajKolory();
	int wczytajBitmapy();

	void narysujRamke(double worldTime, double fps);
	void narysujRamkeZWynikiem(World& world);

	void wyczyscEkran();


	void narysujSwiat(World& world);


	void zaaktualizujEkran();

	void narysujPlansze(World& world);

	void narysujBabyKrowe(BabyKrowa& babyKrowa);

	void narysujPrzeciwnika(Przeciwnik& przeciwnik,double worldTime);

	void narysujGracza(Gracz& gracz,World&world);

	void narysujBeczke(Beczka& beczka, double worldTime);

	void narysujPlatforme(Platforma& platforma);

	void narysujDrabine(Drabina& drabina);

	void narysujBele(Bele&bele);

	void narysujKukurydze(Kukurydza& kukurydza);

	SDL_Surface* wezSurfaceDrabina(int numerKlatki);

};

