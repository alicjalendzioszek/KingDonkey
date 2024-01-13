#pragma once
#include "struktury.h"

class World;
class Gracz;
class Przeciwnik;
class Bele;
class BabyKrowa;
class Okno;
class Beczka;
class Kukurydza;

class Poziom {
public:

	int numerPoziomu = 1;

	void wyborPoziomu(World& world,Okno&okno);

	void stworzPoziom(World& world, Okno& okno);


	void inicjalizacjaDrabiny(World&world,int numerDrabiny,int pozycjaX, int pozycjaY, DlugoscDrabiny dlugosc, bool czyWPlatformie);
	void ustawDrabinieDlugoscPlatformyWKtorejJest(World& world, int numerDrabiny, DlugoscPlatformy dlugoscPlatformyWKtorejJest);

	void inicjalizacjaPlatformy(World& world,int numerPlatformy, int pozycjaX, int pozycjaY, DlugoscPlatformy dlugosc);

	void ustawienieBabyKrowy(BabyKrowa& babyKrowa, int pozycjaX, int pozycjaY);

	void ustawienieGracza(Gracz& gracz,int pozycjaX,int pozycjaY);

	void ustawieniePrzeciwnika(Przeciwnik& przeciwnik, int pozycjaX, int pozycjaY);

	void ustawienieStosuBel(Bele& bele, int pozycjaX, int pozycjaY);

	void inicjalizacjaKukurydzy(World& world, int numerKukurydzy, int pozycjaX, int pozycjaY);

	void ustawienieBeli(Beczka& bela, int pozycjaX, int pozycjaY, double predkosc);
	// ustalic ilosc beczke, ramp i ich pozycje oraz pozycje gracza dla kazdego z poziomow
	void stworzPoziom1(World& world, Okno& okno);

	void stworzPoziom2(World& world, Okno&okno);
									 
	void stworzPoziom3(World& world, Okno&okno);

	


};
