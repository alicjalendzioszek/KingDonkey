#include "World.h"
#define SCREEN_HEIGHT	800
#include <time.h>
#include <cstdlib>


World::World()
{
	gracz.ustawZegar(&zegar);
}

Beczka* World::getBele()
{
	return bele;
}

Platforma* World::getPlatformy()
{
	return platformy;
}

Drabina* World::getDrabiny()
{
	return drabiny;
}

Kukurydza* World::getKukurydze()
{
	return kukurydze;
}

int World::getLiczbaBel()
{
	return liczbaBel;
}

int World::getLiczbaPlatform()
{
	return liczbaPlatform;
}

int World::getLiczbaDrabin()
{
	return liczbaDrabin;
}

int World::getLiczbaKukurydz()
{
	return liczbaKukurydz;
}

bool World::getCzyKoniecPoziomu()
{
	return czyKoniecPoziomu;
}

bool World::getCzyKoniecGry()
{
	return czyKoniecGry;
}

void World::setLiczbaBel(int liczbaBel)
{
	this->liczbaBel = liczbaBel;
}

void World::setLiczbaPlatform(int liczbaPlatform)
{
	this->liczbaPlatform = liczbaPlatform;
}

void World::setLiczbaDrabin(int liczbaDrabin)
{
	this->liczbaDrabin = liczbaDrabin;
}

void World::setLiczbaKukurydz(int liczbaKukurydz)
{
	this->liczbaKukurydz = liczbaKukurydz;
}

void World::setCzyKoniecPoziomu(bool koniec)
{
	this->czyKoniecPoziomu = koniec;
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
	gracz.setRozmiar(okno.graczDrabina2->w / 2, okno.graczDrabina2->h / 2);
	//gracz.rozmiar.x = okno.graczDrabina2->w / 2;
	//gracz.rozmiar.y = okno.graczDrabina2->h / 2;
}

void World::ustalRozmiarPrzeciwnika(Okno& okno)
{
	//tu zalezy ktora bedzie wtedy uzywana jakos to trzeba zapisywac
}

void World::ustalRozmiarBabyKrowy(Okno& okno)
{
	babyKrowa.setRozmiar(okno.babyKrowaSurface->w / 2, okno.babyKrowaSurface->h / 2);
	/*babyKrowa.rozmiar.x = okno.babyKrowaSurface->w / 2;
	babyKrowa.rozmiar.y = okno.babyKrowaSurface->h / 2;*/
}

void World::ustalRozmiarPlatformy(Platforma& platforma, Okno& okno)
{
	if (platforma.getDlugosc() == najkrotsza)
	{
		platforma.setRozmiar(okno.platformaNajkrotsza->w / 2, okno.platformaNajkrotsza->h / 2);
		//platforma.rozmiar.x = okno.platformaNajkrotsza->w / 2;
		//platforma.rozmiar.y = okno.platformaNajkrotsza->h / 2;
	}
	else if (platforma.getDlugosc() == srednia)
	{
		platforma.setRozmiar(okno.platformaSrednia->w / 2, okno.platformaSrednia->h / 2);
		//platforma.rozmiar.x = okno.platformaSrednia->w / 2;
		//platforma.rozmiar.y = okno.platformaSrednia->h / 2;
	}
	else if (platforma.getDlugosc() == najdluzsza)
	{
		platforma.setRozmiar(okno.platformaNajdluzsza->w / 2, okno.platformaNajdluzsza->h / 2);
		//platforma.rozmiar.x = okno.platformaNajdluzsza->w / 2;
		//platforma.rozmiar.y = okno.platformaNajdluzsza->h / 2;
	}
}

void World::ustalRozmiarPlatformyWKtorejJestDrabina(Drabina& drabina, Okno& okno)
{
	if (drabina.getDlugoscPlatformyWKtorejSieZnajduje() == najkrotsza)
	{
		drabina.setRozmiarPlatformyWKtorejJest(okno.platformaNajkrotsza->w / 2, okno.platformaNajkrotsza->h / 2);
	}
	else if (drabina.getDlugoscPlatformyWKtorejSieZnajduje() == srednia)
	{
		drabina.setRozmiarPlatformyWKtorejJest(okno.platformaSrednia->w / 2, okno.platformaSrednia->h / 2);
	}
	else if (drabina.getDlugoscPlatformyWKtorejSieZnajduje() == najdluzsza)
	{
		drabina.setRozmiarPlatformyWKtorejJest(okno.platformaNajdluzsza->w / 2, okno.platformaNajdluzsza->h / 2);
	}
	else
	{
		drabina.setRozmiarPlatformyWKtorejJest(0, 0);
	}

}

void World::ustalRozmiarDrabiny(Drabina& drabina, Okno& okno)
{
	if (drabina.getDlugoscDrabiny() == krotka)
	{
		drabina.setRozmiar(okno.drabinaKrotka->w / 2, okno.drabinaKrotka->h / 2);
	}
	else if (drabina.getDlugoscDrabiny() == dluga)
	{
		drabina.setRozmiar(okno.drabinaDluga->w / 2, okno.drabinaDluga->h / 2);
	}
}

void World::ustalRozmiarStosuBel(Bele& bele, Okno& okno)
{
	bele.setRozmiar(okno.stosBel->w / 2, okno.stosBel->h / 2);
}

void World::ustalRozmiarBeli(Beczka& bela, Okno& okno)
{
	bela.setRozmiar(okno.beczka1->w / 2, okno.beczka1->h / 2);
}

void World::ustalRozmiarKukurydzy(Kukurydza& kukurydza, Okno& okno)
{
	kukurydza.setRozmiar(okno.kukurydzaSurface->w / 2, okno.kukurydzaSurface->h / 2);
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

	if (sprawdzCzyNaDrabinie()) {

		gracz.setCzySpada(false);
		gracz.ustalPredkoscPoDrabinie();

		//szczegolny przypadek gdy stoi na gorze, zrobmy tak zeby mogl skoczyc
		for (int i = 0; i < liczbaDrabin; i++)
		{
			if (gracz.wezX1Zderzen() < drabiny[i].wezX2Zderzen() && gracz.wezX2Zderzen() > drabiny[i].wezX1Zderzen()
				&& gracz.getPozycja().y + gracz.getRozmiar().y >= drabiny[i].wezY1Zderzen() && gracz.getPozycja().y + gracz.getRozmiar().y<drabiny[i].wezY1Zderzen() + 2 * drabiny->getPrzesuniecieZderzenia())
			{
				gracz.setCzyRuchDoDolu(true);
			}

		}

	}
	else {
		sprawdzCzyGraczSpada();
	}

	gracz.zaaktualizujPozycje();

	sprawdzCzyGraczPrzeskakujeBeczke();
	sprawdzKolizjeGracza();
	sprawdzCzyKoniecPoziomu();

}

void World::aktualizujPozycjeBel()
{
	for (int i = 0; i < liczbaBel; i++) {
		if (bele[i].getAktywnosc()) {
			sprawdzCzyBelaSpada(bele[i]);
			bele[i].zaaktualizujPozycjeBeli(this->poziom.getNumerPoziomu());
		}
	}

}

void World::uaktywnijBele()
{
	for (int i = 0; i < liczbaBel; i++)
	{
		int czas = (int)zegar.getWorldTime();
		if (czyUaktywnicBeczke(czas))
		{
			if (bele[i].getAktywnosc() == false)
			{
				bele[i].setAktywnosc(true);
				ostatniaAktywacjaBeczki = czas;
				break;
			}
		}
		else
		{
			break;
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
		|| (gracz.getPozycja().x <= bela.wezX2Zderzen() && gracz.getPozycja().x >= bela.wezX1Zderzen()))
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

bool World::sprawdzCzyGraczStoiNaPlatformie()
{
	for (int i = 0; i < liczbaPlatform; i++)
	{
		if (gracz.wezX1Zderzen() < platformy[i].wezX2Zderzen() && gracz.wezX2Zderzen() > platformy[i].wezX1Zderzen()
			&& gracz.wezY2Zderzen() > platformy[i].wezY1Zderzen() && gracz.wezY2Zderzen() < platformy[i].wezY2Zderzen())
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
		|| (gracz.getPozycja().x <= kukurydza.wezX2Zderzen() && gracz.getPozycja().x >= kukurydza.wezX1Zderzen()))
	{
		if (gracz.getPozycja().y + gracz.getRozmiar().y - gracz.getPrzesuniecieZderzenia() <= kukurydza.wezY2Zderzen() && gracz.getPozycja().y + gracz.getRozmiar().y - gracz.getPrzesuniecieZderzenia() >= kukurydza.wezY1Zderzen())
		{
			return true;
		}
	}
	return false;
}

void World::sprawdzCzyGraczSpada()
{
	gracz.setCzySpada(true);

	for (int i = 0; i < liczbaPlatform; i++)
	{
		if (gracz.wezX1Zderzen() < platformy[i].wezX2Zderzen() && gracz.wezX2Zderzen() > platformy[i].wezX1Zderzen()
			&& gracz.wezY1Zderzen() < platformy[i].wezY2Zderzen() && gracz.wezY2Zderzen() > platformy[i].wezY1Zderzen())
		{

			bool nadPlatforma = gracz.getPozycja().y <= platformy[i].getPozycja().y;
			if (nadPlatforma) {
				gracz.setPozycjaY(platformy[i].wezY1Zderzen() - gracz.getRozmiar().y);
				gracz.setCzySpada(false);
				gracz.setPredkoscY(0);

			}
			else {
				gracz.setPozycjaY(platformy[i].wezY2Zderzen() + gracz.getRozmiar().y + gracz.getPrzesuniecieZderzenia());
				gracz.setPredkoscY(-1 * gracz.getPredkosc().y);
			}

			break;
		}

	}
}

void World::sprawdzCzyGraczPrzeskakujeBeczke()
{
	bool naPlatformie = sprawdzCzyGraczStoiNaPlatformie();
	if (gracz.getCzyDodanoPunktyZaSkok() == false && naPlatformie == false)
	{
		for (int i = 0; i < liczbaBel; i++)
		{
			if (bele[i].getAktywnosc())
			{
				if (gracz.getPozycja().x > bele[i].wezX1Zderzen() && gracz.getPozycja().x < bele[i].wezX2Zderzen())
				{
					if (gracz.wezY2Zderzen() < bele[i].wezY1Zderzen() && gracz.wezY2Zderzen() > bele[i].wezYPrzeskoku())
					{
						if (gracz.getCzyNaDrabinie() == false)
						{
							gracz.setCzyDodanoPunktyZaSkok(true);
							gracz.setCzyAnimacjaPunktowZaSkok(true);
							gracz.zwiekszLiczbePunktowGracza(bele->getLiczbaPunktowZaPrzeskoczenie());
						}
					}
				}
			}

		}
	}
}



void World::sprawdzCzyKoniecPoziomu()
{
	if ((gracz.wezX1Zderzen() >= babyKrowa.wezX1Zderzen() && gracz.wezX1Zderzen() <= babyKrowa.wezX2Zderzen()) || (gracz.wezX2Zderzen() >= babyKrowa.wezX1Zderzen() && gracz.wezX2Zderzen() <= babyKrowa.wezX2Zderzen()))
	{
		if (gracz.wezY2Zderzen() <= babyKrowa.wezY2Zderzen() + 1 && gracz.wezY2Zderzen() >= babyKrowa.wezY1Zderzen())
		{
			czyKoniecPoziomu = true;
			if (poziom.getNumerPoziomu() < 3)
			{
				poziom.zwiekszNumerPoziomu();
			}
			else
			{
				czyKoniecGry = true;
			}
			gracz.zwiekszLiczbePunktowGracza(liczbaPunktowZaPrzejsciePoziomu);
		}
	}

	if (gracz.wezY1Zderzen() > SCREEN_HEIGHT)
	{
		czyKoniecPoziomu = true;
	}
}

bool World::sprawdzCzyNaDrabinie()
{
	gracz.setCzyNaDrabinie(false);
	for (int i = 0; i < liczbaDrabin; i++)
	{
		if (gracz.wezX1Zderzen() < drabiny[i].wezX2Zderzen() && gracz.wezX2Zderzen() > drabiny[i].wezX1Zderzen()
			&& gracz.wezY1Zderzen() < drabiny[i].wezY2Zderzen() && gracz.wezY2Zderzen() > drabiny[i].wezY1Zderzen() && gracz.wezY2Zderzen() < drabiny[i].wezY2Zderzen())
		{
			gracz.setCzyNaDrabinie(true);

			bool jestNadDrabina = gracz.wezY1Zderzen() < drabiny[i].getPozycja().y;

			if (jestNadDrabina == false) {
				for (int i = 0; i < liczbaPlatform; i++)
				{
					if (gracz.wezX1Zderzen() < platformy[i].wezX2Zderzen() && gracz.wezX2Zderzen() > platformy[i].wezX1Zderzen()
						&& gracz.wezY1Zderzen() < platformy[i].wezY2Zderzen() && gracz.wezY2Zderzen() > platformy[i].wezY1Zderzen())
					{
						if (gracz.wezY1Zderzen() < platformy[i].wezY1Zderzen()) {
							gracz.setPozycjaY(platformy[i].wezY1Zderzen() - gracz.getRozmiar().y);
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
	bela.setCzySpada(true);

	for (int i = 0; i < liczbaPlatform; i++)
	{
		if (bela.wezX1Zderzen() < platformy[i].wezX2Zderzen() && bela.wezX2Zderzen() > platformy[i].wezX1Zderzen()
			&& bela.wezY1Zderzen() < platformy[i].wezY2Zderzen() && bela.wezY2Zderzen() > platformy[i].wezY1Zderzen())
		{

			bool nadPlatforma = bela.getPozycja().y <= platformy[i].getPozycja().y;
			if (nadPlatforma) {
				bela.setPozycjaY(platformy[i].wezY1Zderzen() - bela.getRozmiar().y);
				bela.setCzySpada(false);
				bela.setPredkoscY(0);
				if (bela.getCzyMialMiejsceUpadek())
				{
					bela.zwiekszLiczbeUpadkow();
					bela.setCzyZmienionoPredkosc(false);
					bela.setCzyMialMiejsceUpadek(false);
				}
			}
			break;
		}
	}

	if (bela.getCzySpada())
	{
		bela.setCzyMialMiejsceUpadek(true);
	}
}


void World::sprawdzKolizjeZBeczkami()
{
	for (int i = 0; i < liczbaBel; i++) {
		if (bele[i].getAktywnosc()) {
			bool kolizja = sprawdzCzyKolizjaZBeczka(gracz, bele[i]);

			if (kolizja) {
				bool naPlatformie = sprawdzCzyGraczStoiNaPlatformie();

				if (gracz.getCzyDodanoPunktyZaSkok() && naPlatformie == false && gracz.getCzyNaDrabinie() == false)
				{
					gracz.zmniejszLiczbePunktowGracza(bele->getLiczbaPunktowZaPrzeskoczenie());
					gracz.setCzyAnimacjaPunktowZaSkok(false);
					gracz.setCzyAnimacjaPunktowZaZebranieBonusa(false);
				}

				czyKoniecPoziomu = true;
				break;
			}
		}
	}
}

void World::sprawdzKolizjeZKukurydzami()
{
	for (int i = 0; i < liczbaKukurydz; i++) {
		if (kukurydze[i].getCzyAktywna()) {
			bool kolizja = sprawdzCzyKolizjaZBonusem(gracz,kukurydze[i]);

			if (kolizja) {
				gracz.setCzyAnimacjaPunktowZaZebranieBonusa(true);
				gracz.zwiekszLiczbePunktowGracza(kukurydze->getLiczbaPunktowKukurydza());

				kukurydze[i].setCzyAktywna(false);
				break;
			}
		}
	}
}

void World::sprawdzKolizjeGracza()
{
	sprawdzKolizjeZBeczkami();
	sprawdzKolizjeZKukurydzami();
}

bool World::czyUaktywnicBeczke(int czas)
{
	//const int przesuniecieWCzasie = 5;
	int przesuniecieWCzasie = rand() % 2;
	if ((przesuniecieWCzasie==0) && (ostatniaAktywacjaBeczki != czas)) {
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

void World::setOstatniaAktywacjaBeczki(int czas)
{
	this->ostatniaAktywacjaBeczki = czas;
}
