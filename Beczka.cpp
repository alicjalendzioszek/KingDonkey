#include "Beczka.h"
#include <cstdlib>
#include <time.h>

XY Beczka::getPozycja()
{
	return pozycja;
}

void Beczka::setPredkoscX(double predkoscX)
{
	this->predkosc.x = predkoscX;
}

void Beczka::setPredkoscY(double predkoscY)
{
	this->predkosc.y = predkoscY;
}

void Beczka::setPredkoscStartX(double predkoscX)
{
	this->predkoscStart.x = predkoscX;
}

void Beczka::setPozycjaY(double y)
{
	this->pozycja.y = y;
}

void Beczka::zwiekszLiczbeUpadkow()
{
	this->liczbaUpadkow++;
}

void Beczka::setCzyZmienionoPredkosc(bool czyZmianaPredkosci)
{
	this->czyZmienionoPredkosc = czyZmianaPredkosci;
}

void Beczka::setCzyMialMiejsceUpadek(bool czyMialMiejsceUpadek)
{
	this->czyMialMiejsceUpadek = czyMialMiejsceUpadek;
}

void Beczka::setPozycja(double x, double y)
{
	this->pozycja.x = x;
	this->pozycja.y = y;
}

void Beczka::setRozmiar(double x, double y)
{
	this->rozmiar.x = x;
	this->rozmiar.y = y;
}

void Beczka::setAktywnosc(bool aktywnosc)
{
	this->czyAktywna = aktywnosc;
}

void Beczka::setPozycjaStartowa(double x, double y)
{
	this->pozycjaStartowa.x = x;
	this->pozycjaStartowa.y = y;
}

void Beczka::setCzySpada(bool spadek)
{
	this->czySpada = spadek;
}

bool Beczka::getAktywnosc()
{
	return czyAktywna;
}

double Beczka::getPoczatkowaPredkosc()
{
	return poczatkowaPredkosc;
}

bool Beczka::getCzySpada()
{
	return czySpada;
}

int Beczka::getLiczbaPunktowZaPrzeskoczenie()
{
	return liczbaPunktowZaPrzeskoczenie;
}

bool Beczka::getCzyMialMiejsceUpadek()
{
	return czyMialMiejsceUpadek;
}

int Beczka::getLiczbaUpadkow()
{
	return liczbaUpadkow;
}

XY Beczka::getRozmiar()
{
	return rozmiar;
}

Beczka::Beczka()
{

}

void Beczka::zaaktualizujPozycjeBeli(int numerPoziomu)
{
	auto delta = zegar->getDelta();

	if (wezY2Zderzen() >= SCREEN_HEIGHT)
	{
		resetujBeczke();
	}

	auto delte = zegar->getDelta();

	if (czySpada)
	{
		predkosc.y = predkosc.y + (delte * predkoscZmianyWSpadku);

	}

	if (numerPoziomu == 1)
	{
		aktualizacjaPredkosciPoziom1();
	}
	else if (numerPoziomu == 2)
	{
		aktualizacjaPredkosciPoziom2();
	}
	else if (numerPoziomu == 3)
	{
		aktualizacjaPredkosciPoziom3();
	}

	aktualizacjaPozycji(pozycja, predkosc, delta);
}

void Beczka::aktualizacjaPredkosciPoziom1()
{
	if (liczbaUpadkow == poczatkowaLiczbaUpadkow && czyZmienionoPredkosc == false)
	{
		predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		czyZmienionoPredkosc = true;
	}
	else if (liczbaUpadkow == poczatkowaLiczbaUpadkow + 1 && czyZmienionoPredkosc == false)
	{
		predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		czyZmienionoPredkosc = true;
	}
	else if (liczbaUpadkow == poczatkowaLiczbaUpadkow + 2 && czyZmienionoPredkosc == false)
	{
		predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		czyZmienionoPredkosc = true;
	}
}

void Beczka::aktualizacjaPredkosciPoziom2()
{
	if (liczbaUpadkow == poczatkowaLiczbaUpadkow && czyZmienionoPredkosc == false)
	{
		predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		czyZmienionoPredkosc = true;
	}
}

void Beczka::aktualizacjaPredkosciPoziom3()
{
	if (liczbaUpadkow == poczatkowaLiczbaUpadkow && czyZmienionoPredkosc == false) 
	{
		int strona = 0;
		strona = rand() % 2; //0 lub 1 wypadnie
		if (strona == 0)
		{
			predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		}
		czyZmienionoPredkosc = true;
	}
	else if (liczbaUpadkow == poczatkowaLiczbaUpadkow + 1 && czyZmienionoPredkosc == false)
	{
		//nic
	}
	else if (liczbaUpadkow == poczatkowaLiczbaUpadkow + 2 && czyZmienionoPredkosc == false)
	{
		predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		czyZmienionoPredkosc = true;
	}
}

void Beczka::resetujBeczke()
{
	pozycja.x = pozycjaStartowa.x;
	pozycja.y = pozycjaStartowa.y;
	czyAktywna = false;
	czyMialMiejsceUpadek = false;
	czyZmienionoPredkosc = false;
	liczbaUpadkow = 0;
	czySpada = false;
	predkosc.x = predkoscStart.x;
	predkosc.y = 0;
	
}

double Beczka::wezX1Zderzen()
{
	return this->pozycja.x - this->rozmiar.x - przesuniecieZderzenia;
}

double Beczka::wezX2Zderzen()
{
	return this->pozycja.x + this->rozmiar.x + przesuniecieZderzenia;
}

double Beczka::wezY1Zderzen()
{
	return this->pozycja.y - this->rozmiar.y - przesuniecieZderzenia;
}

double Beczka::wezY2Zderzen()
{
	return this->pozycja.y + this->rozmiar.y + przesuniecieZderzenia;
}

double Beczka::wezYPrzeskoku()
{
	return this->pozycja.y - this->rozmiar.y - przesunieciePrzeskoku;
}

void Beczka::ustawZegar(Zegar* zegar)
{
	this->zegar = zegar;
}
