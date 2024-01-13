#include "World.h"
#define SCREEN_HEIGHT	800
//todo usunac
#include <iostream>


World::World()
{
	gracz.ustawZegar(&zegar);
}

void World::utworzSwiat(Okno& okno)
{
	poziom.wyborPoziomu(*this, okno);
}

void World::ustalRozmiarGracza(Okno& okno)
{
	/*if (gracz.czyNaDrabinie == false)
	{
		gracz.rozmiar.x = okno.graczPrawo->w / 2;
		gracz.rozmiar.y = okno.graczPrawo->h / 2;
	}
	else
	{
		gracz.rozmiar.x = okno.graczDrabina2->w / 2;
		gracz.rozmiar.y = okno.graczDrabina2->h / 2;
	}*/
	gracz.rozmiar.x = okno.graczDrabina2->w / 2;
	gracz.rozmiar.y = okno.graczDrabina2->h / 2;
}

void World::ustalRozmiarPrzeciwnika(Okno& okno)
{
	//tu zalezy ktora bedzie wtedy uzywana jakos to trzeba zapisywac
}

void World::ustalRozmiarBabyKrowy(Okno& okno)
{
	babyKrowa.rozmiar.x = okno.babyKrowaSurface->w / 2;
	babyKrowa.rozmiar.y = okno.babyKrowaSurface->h / 2;
}

void World::ustalRozmiarPlatformy(Platforma& platforma, Okno& okno)
{
	if (platforma.dlugosc == najkrotsza)
	{
		platforma.rozmiar.x = okno.platformaNajkrotsza->w / 2;
		platforma.rozmiar.y = okno.platformaNajkrotsza->h / 2;
	}
	else if (platforma.dlugosc == srednia)
	{
		platforma.rozmiar.x = okno.platformaSrednia->w / 2;
		platforma.rozmiar.y = okno.platformaSrednia->h / 2;
	}
	else if (platforma.dlugosc == najdluzsza)
	{
		platforma.rozmiar.x = okno.platformaNajdluzsza->w / 2;
		platforma.rozmiar.y = okno.platformaNajdluzsza->h / 2;
	}
}

void World::ustalRozmiarPlatformyWKtorejJestDrabina(Drabina& drabina, Okno& okno)
{
	if (drabina.dlugoscPlatformyWKtorejSieZnajduje == najkrotsza)
	{
		drabina.rozmiarPlatformyWKtorejJest.x = okno.platformaNajkrotsza->w / 2;
		drabina.rozmiarPlatformyWKtorejJest.y = okno.platformaNajkrotsza->h / 2;
	}
	else if (drabina.dlugoscPlatformyWKtorejSieZnajduje == srednia)
	{
		drabina.rozmiarPlatformyWKtorejJest.x = okno.platformaSrednia->w / 2;
		drabina.rozmiarPlatformyWKtorejJest.y = okno.platformaSrednia->h / 2;
	}
	else if (drabina.dlugoscPlatformyWKtorejSieZnajduje == najdluzsza)
	{
		drabina.rozmiarPlatformyWKtorejJest.x = okno.platformaNajdluzsza->w / 2;
		drabina.rozmiarPlatformyWKtorejJest.y = okno.platformaNajdluzsza->h / 2;
	}
	else
	{
		drabina.rozmiarPlatformyWKtorejJest.x = 0;
		drabina.rozmiarPlatformyWKtorejJest.y = 0;
	}

}

void World::ustalRozmiarDrabiny(Drabina& drabina, Okno& okno)
{
	if (drabina.dlugosc == krotka)
	{
		drabina.rozmiar.x = okno.drabinaKrotka->w / 2;
		drabina.rozmiar.y = okno.drabinaKrotka->h / 2;
	}
	else if (drabina.dlugosc == dluga)
	{
		drabina.rozmiar.x = okno.drabinaDluga->w / 2;
		drabina.rozmiar.y = okno.drabinaDluga->h / 2;
	}
}

void World::ustalRozmiarStosuBel(Bele& bele, Okno& okno)
{
	bele.rozmiar.x = okno.stosBel->w / 2;
	bele.rozmiar.y = okno.stosBel->h / 2;
}

void World::ustalRozmiarBeli(Beczka& bela, Okno& okno)
{
	bela.rozmiar.x = okno.beczka1->w / 2;
	bela.rozmiar.y = okno.beczka1->h / 2;
}

void World::ustalRozmiarKukurydzy(Kukurydza& kukurydza, Okno& okno)
{
	kukurydza.rozmiar.x = okno.kukurydzaSurface->w / 2;
	kukurydza.rozmiar.y = okno.kukurydzaSurface->h / 2;
}

void World::wykonajTure(Okno& okno)
{
	event.readEvents(*this, okno);
	zaktualizujSwiat();
}

void World::zaktualizujSwiat()
{

	uaktywnijBele();
	aktualizujPozycjeBel();

	//poruszaniePoDrabinieWdol


	if (sprawdzCzyNaDrabinie()) {
		gracz.czySpada = false;
		gracz.ustalPredkoscPoDrabinie();

		//szczegolny przypadek gdy stoi na gorze, zrobmy tak zeby mogl skoczyc
		for (int i = 0; i < liczbaDrabin; i++)
		{
			if (gracz.wezX1Zderzen() < drabiny[i].wezX2Zderzen() && gracz.wezX2Zderzen() > drabiny[i].wezX1Zderzen()
				&& gracz.pozycja.y+gracz.rozmiar.y>= drabiny[i].wezY1Zderzen()&& gracz.pozycja.y + gracz.rozmiar.y<drabiny[i].wezY1Zderzen()+2*drabiny->przesuniecieZderzenia)
			{
				gracz.czyRuchDoDolu = true;
			}

		}

	}
	else {
		sprawdzCzyGraczSpada();
	}

	//gracz.czySpada = false;
	//ograniczamy bok okna
	
	gracz.zaaktualizujPozycje();
	/*if (gracz.pozycja.y+gracz.rozmiar.y < platformy[indeksNajblizszejPlatformy].pozycja.y + platformy[indeksNajblizszejPlatformy].rozmiar.y && gracz.pozycja.y + gracz.rozmiar.y > platformy[indeksNajblizszejPlatformy].pozycja.y - platformy[indeksNajblizszejPlatformy].rozmiar.y)
	{
		gracz.pozycja.y = platformy[indeksNajblizszejPlatformy].pozycja.y - platformy[indeksNajblizszejPlatformy].rozmiar.y;
		printf("ustawiono pozycje %f",gracz.pozycja.y);
		gracz.czySpada = false;
	}*/


	sprawdzKolizjeGracza();
	sprawdzCzyKoniecPoziomu();

}

void World::aktualizujPozycjeBel()
{
	for (int i = 0; i < liczbaBel; i++) {
		if (bele[i].czyAktywna == true) {
			sprawdzCzyBelaSpada(bele[i]);
			bele[i].zaaktualizujPozycjeBeli(this->poziom.numerPoziomu);
		}
	}

}

void World::uaktywnijBele()
{
	for (int i = 0; i < liczbaBel; i++)
	{
		int czas = (int)zegar.wezWorldTime();
		if (czyUaktywnicBeczke(czas))
		{
			if (bele[i].czyAktywna == false)
			{
				bele[i].czyAktywna = true;
				ostatniaAktywacjaBeczki = (int)zegar.wezWorldTime();
				break;
			}
		}
	}
}

void World::alokacjaPlatform()
{
	platformy = new Platforma[liczbaPlatform];
}

void World::zwalnianiePamieciPlatform()
{
	delete[]platformy;
}

void World::alokacjaDrabin()
{
	drabiny = new Drabina[liczbaDrabin];
}

void World::zwalnianiePamieciDrabin()
{
	delete[]drabiny;
}

void World::alokacjaBel()
{
	bele = new Beczka[liczbaBel];
	for (int i = 0; i < liczbaBel; i++) {
		bele[i].ustawZegar(&zegar);
	}
}

void World::zwalnianiePamieciBel()
{
	delete[] bele;
}

void World::alokacjaKukurydz()
{
	kukurydze = new Kukurydza[liczbaKukurydz];
}

void World::zwalnianiePamieciKukurydz()
{
	delete[] kukurydze;
}

bool World::sprawdzCzyKolizjaZBeczka(Gracz& gracz, Beczka& bela)
{
	//najpierw sprawdzamy czy prawa krawedz, srodek lub lewa krawedz gracza znajduje sie wewnatrz beli (dotyka jej)
	if ((gracz.wezX1Zderzen() <= bela.wezX2Zderzen() && gracz.wezX1Zderzen() >= bela.wezX1Zderzen())
		|| (gracz.wezX2Zderzen() <= bela.wezX2Zderzen() && gracz.wezX2Zderzen() >= bela.wezX1Zderzen())
		|| (gracz.pozycja.x <= bela.wezX2Zderzen() && gracz.pozycja.x >= bela.wezX1Zderzen()))
	{
		//sprawdzamy czy gorna krawedz lub dolna krawedz gracza znajduje sie wewnatrz beli (dotyka jej)
		if ((gracz.wezY1Zderzen() <= bela.wezY2Zderzen() && gracz.wezY1Zderzen() >= bela.wezY1Zderzen())
			|| (gracz.wezY2Zderzen() <= bela.wezY2Zderzen() && gracz.wezY2Zderzen() >= bela.wezY1Zderzen()))
		{
			return true;
		}
	}
	return false;
}

bool World::sprawdzCzyKolizjaZBonusem(Gracz& gracz, Kukurydza& kukurydza)
{
	if ((gracz.wezX1Zderzen() <= kukurydza.wezX2Zderzen() && gracz.wezX1Zderzen() >= kukurydza.wezX1Zderzen())
		|| (gracz.wezX2Zderzen() <= kukurydza.wezX2Zderzen() && gracz.wezX2Zderzen() >= kukurydza.wezX1Zderzen())
		|| (gracz.pozycja.x <= kukurydza.wezX2Zderzen() && gracz.pozycja.x >= kukurydza.wezX1Zderzen()))
	{
		//sprawdzamy czy gorna krawedz lub dolna krawedz gracza znajduje sie wewnatrz beli (dotyka jej)
		if (gracz.pozycja.y+gracz.rozmiar.y-gracz.przesuniecieZderzenia <= kukurydza.wezY2Zderzen() && gracz.pozycja.y + gracz.rozmiar.y - gracz.przesuniecieZderzenia >= kukurydza.wezY1Zderzen())
		{
			return true;
		}
	}
	return false;
}

void World::sprawdzCzyGraczSpada()
{

	// dodac czeka na podloge dolna planszy

	gracz.czySpada = true;

	for (int i = 0; i < liczbaPlatform; i++)
	{
		if (gracz.wezX1Zderzen() < platformy[i].wezX2Zderzen() && gracz.wezX2Zderzen() > platformy[i].wezX1Zderzen()
			&& gracz.wezY1Zderzen() < platformy[i].wezY2Zderzen() && gracz.wezY2Zderzen() > platformy[i].wezY1Zderzen())
		{

			bool nadPlatforma = gracz.pozycja.y <= platformy[i].pozycja.y;
			if (nadPlatforma) {
				gracz.pozycja.y = platformy[i].wezY1Zderzen() - gracz.rozmiar.y;
				gracz.czySpada = false;
				gracz.predkosc.y = 0;

			}
			else {
				gracz.pozycja.y = platformy[i].wezY2Zderzen() + gracz.rozmiar.y + gracz.przesuniecieZderzenia;
				gracz.predkosc.y = -1 * gracz.predkosc.y;
			}

			break;
		}

	}
}



void World::sprawdzCzyKoniecPoziomu()
{
	if ((gracz.wezX1Zderzen() >= babyKrowa.wezX1Zderzen() && gracz.wezX1Zderzen() <= babyKrowa.wezX2Zderzen()) || (gracz.wezX2Zderzen() >= babyKrowa.wezX1Zderzen() && gracz.wezX2Zderzen() <= babyKrowa.wezX2Zderzen()))
	{
		if (gracz.wezY2Zderzen() <= babyKrowa.wezY2Zderzen() + 1 && gracz.wezY2Zderzen() >= babyKrowa.wezY1Zderzen())//magic
		{
			czyKoniecPoziomu = true;
			if (poziom.numerPoziomu < 3)
			{
				poziom.numerPoziomu++;
			}
			else
			{
				czyKoniecGry = true;
			}
			gracz.liczbaPunktowGracza += lliczbaPunktowZaPrzejsciePoziomu;
		}
	}

	//if(wezY2Zderzen()>)
	if (gracz.wezY1Zderzen() > SCREEN_HEIGHT)//MAGIC NUMBER TODO TO DO KONIECCZNIEEEEEEEEEEEEEEEEEE
	{
		czyKoniecPoziomu = true;
	}
}

bool World::sprawdzCzyNaDrabinie()
{
	gracz.czyNaDrabinie = false;
	for (int i = 0; i < liczbaDrabin; i++)
	{
		if (gracz.wezX1Zderzen() < drabiny[i].wezX2Zderzen() && gracz.wezX2Zderzen() > drabiny[i].wezX1Zderzen()
			&& gracz.wezY1Zderzen() < drabiny[i].wezY2Zderzen() && gracz.wezY2Zderzen() > drabiny[i].wezY1Zderzen() && gracz.wezY2Zderzen() < drabiny[i].wezY2Zderzen())
		{

			gracz.czyNaDrabinie = true;

			bool jestNadDrabina = gracz.wezY1Zderzen() < drabiny[i].pozycja.y;

			if (jestNadDrabina == false) {
				for (int i = 0; i < liczbaPlatform; i++)
				{
					if (gracz.wezX1Zderzen() < platformy[i].wezX2Zderzen() && gracz.wezX2Zderzen() > platformy[i].wezX1Zderzen()
						&& gracz.wezY1Zderzen() < platformy[i].wezY2Zderzen() && gracz.wezY2Zderzen() > platformy[i].wezY1Zderzen())
					{
						if (gracz.wezY1Zderzen() < platformy[i].wezY1Zderzen()) {
							gracz.pozycja.y = platformy[i].wezY1Zderzen() - gracz.rozmiar.y;
							break;
						}
					}
				}
			}

			return true;

		}
	}


	return false;
}

void World::sprawdzCzyBelaSpada(Beczka& bela)
{
	bela.czySpada = true;

	for (int i = 0; i < liczbaPlatform; i++)
	{
		if (bela.wezX1Zderzen() < platformy[i].wezX2Zderzen() && bela.wezX2Zderzen() > platformy[i].wezX1Zderzen()
			&& bela.wezY1Zderzen() < platformy[i].wezY2Zderzen() && bela.wezY2Zderzen() > platformy[i].wezY1Zderzen())
		{

			bool nadPlatforma = bela.pozycja.y <= platformy[i].pozycja.y;
			if (nadPlatforma) {
				bela.pozycja.y = platformy[i].wezY1Zderzen() - bela.rozmiar.y;
				bela.czySpada = false;
				bela.predkosc.y = 0;
				if (bela.czyMialMiejsceUpadek)
				{
					bela.liczbaUpadkow++;
					bela.czyZmienionoPredkosc = false;
					bela.czyMialMiejsceUpadek = false;
				}

			}

			break;
		}
	}

	if (bela.czySpada)
	{
		bela.czyMialMiejsceUpadek = true;
	}
}

//void World::sprawdzCzyGraczSpada()
//{
//	// sprawdz czy gracz ma pod soba rampe lub podloge
//	//sprawdzCzyGraczSpada();
//
//}

void World::sprawdzKolizjeZBeczkami()
{
	for (int i = 0; i < liczbaBel; i++) {
		if (bele[i].czyAktywna == true) {
			bool kolizja = sprawdzCzyKolizjaZBeczka(gracz, bele[i]);

			if (kolizja) {
				// todo gracz traci zycie czy cos
				//poziom.numerPoziomu = 1;
				czyKoniecPoziomu = true;
				//czyKoniecGry = true;
				/*gracz.pozycja.x = gracz.pozycjaStartowa.x;
				gracz.pozycja.y = gracz.pozycjaStartowa.y;
				bele[i].resetujBeczke();*/
				break;
			}
		}
	}
}

void World::sprawdzKolizjeZKukurydzami()
{
	for (int i = 0; i < liczbaKukurydz; i++) {
		if (kukurydze[i].czyAktywna == true) {
			bool kolizja = sprawdzCzyKolizjaZBonusem(gracz,kukurydze[i]);

			if (kolizja) {
				gracz.liczbaPunktowGracza += kukurydze->liczbaPunktowKukurydza;
				kukurydze[i].czyAktywna = false;
				break;
			}
		}
	}
}

void World::sprawdzKolizjeGracza()
{
	sprawdzKolizjeZBeczkami();
	sprawdzKolizjeZKukurydzami();
	//sprawdzCzyGraczSpada();
}

bool World::czyUaktywnicBeczke(int czas)
{
	const int przesuniecieWCzasie = 5;
	if ((czas % czasTworzeniaNowejBeczki == przesuniecieWCzasie) && (ostatniaAktywacjaBeczki != czas)) {
		return true;
	}
	else {
		return false;
	}
}

void World::czekaj()
{
	const double oczekiwanyCzasKlatki = 30; // ms
	while (true) {
		if (zegar.podejrzyjDelteMS() >= oczekiwanyCzasKlatki) {
			break;
		}
	}
}
