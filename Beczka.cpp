#include "Beczka.h"
#include <cstdlib>
#include <time.h>

Beczka::Beczka()
{
	//predkosc.x = poczatkowaPredkosc;
}



void Beczka::zaaktualizujPozycjeBeli(int numerPoziomu)
{
	auto delta = zegar->wezDelte();
	//zmienic to ze po prostu wypada za okno TODO
	if (wezY2Zderzen() >= SCREEN_HEIGHT)
	{
		resetujBeczke();
	}

	auto delte = zegar->wezDelte();

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
	else if (liczbaUpadkow == poczatkowaLiczbaUpadkow+1 && czyZmienionoPredkosc == false)
	{
		predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		czyZmienionoPredkosc = true;
	}
	else if (liczbaUpadkow == poczatkowaLiczbaUpadkow+2 && czyZmienionoPredkosc == false)
	{
		predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		czyZmienionoPredkosc = true;
	}
}

void Beczka::aktualizacjaPredkosciPoziom2()
{
	if (liczbaUpadkow == poczatkowaLiczbaUpadkow && czyZmienionoPredkosc == false) //magic TODO bo ten pierwszy upadek to jest liczony jako po prostu dostosowanie wysokosci beczki bo nie da sie idealnie
	{
		predkosc.x = -1 * predkosc.x; //zmieniamy jej kierunek ruchu
		czyZmienionoPredkosc = true;
	}
}

void Beczka::aktualizacjaPredkosciPoziom3()
{
	if (liczbaUpadkow == poczatkowaLiczbaUpadkow && czyZmienionoPredkosc == false) //magic TODO bo ten pierwszy upadek to jest liczony jako po prostu dostosowanie wysokosci beczki bo nie da sie idealnie
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
	//klatka = 0;
	predkosc.x = predkoscStart.x;
	predkosc.y = 0;

}

//void Beczka::zaaktualizujPozycje()
//{
//	auto delte = zegar.obliczDelte();
//	aktualizacjaPozycji(pozycja, predkosc, delte);
//
//	// czy pozycja koncowa 
//}
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

void Beczka::ustawZegar(Zegar* zegar)
{
	this->zegar = zegar;
}
