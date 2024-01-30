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
#include "wymiaryOkna.h"

class World
{
private:

	Beczka* bele = nullptr;
	Platforma* platformy = nullptr;
	Drabina* drabiny = nullptr;
	Kukurydza* kukurydze = nullptr;

	bool czyKoniecGry = false;
	bool czyKoniecPoziomu = false;

	int ostatniaAktywacjaBeczki = 0;
	int czasTworzeniaNowejBeczki = 6; // w sekundach
	int liczbaBel = 0;
	int liczbaPlatform = 0;
	int liczbaDrabin = 0;
	int liczbaKukurydz = 0;
	const int liczbaPunktowZaPrzejsciePoziomu = 1000;

public:
	World();

	Event event;
	Poziom poziom;
	Zegar zegar;
	Gracz gracz;
	Przeciwnik przeciwnik;
	Bele stosBel;
	BabyKrowa babyKrowa;

	Beczka* getBele();
	Platforma* getPlatformy();
	Drabina* getDrabiny();
	Kukurydza* getKukurydze();

	int getLiczbaBel();
	int getLiczbaPlatform();
	int getLiczbaDrabin();
	int getLiczbaKukurydz();
	bool getCzyKoniecPoziomu();
	bool getCzyKoniecGry();

	void setLiczbaBel(int liczbaBel);
	void setLiczbaPlatform(int liczbaPlatform);
	void setLiczbaDrabin(int liczbaDrabin);
	void setLiczbaKukurydz(int liczbaKukurydz);
	void setCzyKoniecPoziomu(bool koniec);

	void utworzSwiat(Okno& okno);

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

	bool sprawdzCzyGraczStoiNaPlatformie();

	bool sprawdzCzyKolizjaZBonusem(Gracz& gracz, Kukurydza& kukurydza);

	void sprawdzCzyGraczSpada();

	void sprawdzCzyGraczPrzeskakujeBeczke();

	void sprawdzCzyKoniecPoziomu();

	bool sprawdzCzyNaDrabinie();

	void sprawdzCzyBelaSpada(Beczka&bela);

	void sprawdzKolizjeZBeczkami();
	void sprawdzKolizjeZKukurydzami();

	void sprawdzKolizjeGracza();

	bool czyUaktywnicBeczke(int czas);
	void czekaj();

	void setOstatniaAktywacjaBeczki(int czas);

};

