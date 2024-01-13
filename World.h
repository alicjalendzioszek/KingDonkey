#pragma once

#include "Event.h"
#include "Zegar.h"
#include "Gracz.h"
#include "Przeciwnik.h"
#include "Beczka.h"
#include "Okno.h"
#include "Platforma.h"
#include "Poziom.h"
#include "Drabina.h"
#include "Bele.h"
#include "BabyKrowa.h"
#include "Kukurydza.h"


class World
{
public:
	World();

	Event event;
	Poziom poziom;
	Zegar zegar;
	Gracz gracz;
	Przeciwnik przeciwnik;
	Bele stosBel;
	BabyKrowa babyKrowa;

	int liczbaBel = 0;
	Beczka* bele = nullptr;

	int liczbaPlatform = 0;
	Platforma* platformy = nullptr;

	int liczbaDrabin = 0;
	Drabina* drabiny = nullptr;

	int liczbaKukurydz = 0;
	Kukurydza* kukurydze = nullptr;

	bool czyKoniecGry = false;
	bool czyKoniecPoziomu = false;
	int lliczbaPunktowZaPrzejsciePoziomu = 1000;
	//double najWyzszaZNich = 1000;
	//double najblizszaOdlegloscOdGraczaX = 1000;
	//int indeksNajblizszejPlatformy = 0;

	void utworzSwiat(Okno& okno);
	//bedziemy do pozycji x gracza dodawac rozmiar(czyli polowe szerokosci) zeby sprawdzic kolizje
	//void ustalRozmiaryObiektow(Okno &okno);

	void ustalRozmiarGracza(Okno& okno);
	void ustalRozmiarPrzeciwnika(Okno& okno);

	void ustalRozmiarBabyKrowy(Okno& okno);

	void ustalRozmiarPlatformy(Platforma& platforma, Okno& okno);
	void ustalRozmiarPlatformyWKtorejJestDrabina(Drabina& drabina, Okno& okno);


	void ustalRozmiarDrabiny(Drabina& drabina, Okno& okno);
	void ustalRozmiarStosuBel(Bele& bele, Okno& okno);

	void ustalRozmiarBeli(Beczka& bela, Okno& okno);

	void ustalRozmiarKukurydzy(Kukurydza& kukurydza,Okno&okno);

	void wykonajTure(Okno& okno);

	void zaktualizujSwiat();

	void aktualizujPozycjeBel();
	void uaktywnijBele();

	void alokacjaPlatform();
	void zwalnianiePamieciPlatform();

	void alokacjaDrabin();
	void zwalnianiePamieciDrabin();

	void alokacjaBel();
	void zwalnianiePamieciBel();

	void alokacjaKukurydz();
	void zwalnianiePamieciKukurydz();



	bool sprawdzCzyKolizjaZBeczka(Gracz& gracz, Beczka& bela);

	bool sprawdzCzyKolizjaZBonusem(Gracz& gracz, Kukurydza& kukurydza);

	void sprawdzCzyGraczSpada();

	void sprawdzCzyKoniecPoziomu();

	bool sprawdzCzyNaDrabinie();

	void sprawdzCzyBelaSpada(Beczka&bela);

	void sprawdzKolizjeZBeczkami();
	void sprawdzKolizjeZKukurydzami();

	void sprawdzKolizjeGracza();

	bool czyUaktywnicBeczke(int czas);
	void czekaj();

private:
	int ostatniaAktywacjaBeczki = 0;
	int czasTworzeniaNowejBeczki = 6; // w sekundach


};

