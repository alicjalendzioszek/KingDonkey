#include "Gracz.h"
//#include "Gracz.h"
#define SCREEN_WIDTH	1400
#define SCREEN_HEIGHT	800

// remove
#include <iostream>

Gracz::Gracz()
{
}

void Gracz::zaaktualizujPozycje()
{
	auto delte = zegar->wezDelte();
	/*if (this->numerKlatki == 0) {
		delte = 0;
	}*/

	bool czyAktualizujemy = false;

	if (wezX1Zderzen() <= 0 &&czyRuchWPrawo==false)
	{
		//nie aktualizujemy
	}
	else if (wezX2Zderzen() >= SCREEN_WIDTH && czyRuchWPrawo)
	{
		//nie aktualizujemy
	}
	else if (wezY1Zderzen() <= 0)
	{
		pozycja.y = 0 + rozmiar.y + 2*przesuniecieZderzenia;
		predkosc.y = -1 * predkosc.y;
		czySpada = true;
		czyAktualizujemy = true;
	}
	else
	{
		czyAktualizujemy = true;
		
	}
	
	if (czySpada) {
		predkosc.y = predkosc.y + (delte * predkoscZmianyWSpadku);
		czySkoczyl = false;
	}
	else {
		if (czySkoczyl) {
			if (czyNaDrabinie == false)
			{
				predkosc.y = predkoscSkoku;
			}
			else if (czyNaDrabinie && czyRuchDoDolu)
			{
				predkosc.y = predkoscSkoku;
			}
			czySkoczyl = false;
			czyRuchDoDolu = false;
		}
	}
	

	if (czyAktualizujemy)
	{
		aktualizacjaPozycji(pozycja, predkosc, delte);
	}
}


double Gracz::wezX1Zderzen()
{
	return this->pozycja.x - this->rozmiar.x - przesuniecieZderzenia;
}

double Gracz::wezX2Zderzen()
{
	return this->pozycja.x + this->rozmiar.x + przesuniecieZderzenia;
}

double Gracz::wezY1Zderzen()
{
	return this->pozycja.y - this->rozmiar.y - przesuniecieZderzenia;
}

double Gracz::wezY2Zderzen()
{
	return this->pozycja.y + this->rozmiar.y + przesuniecieZderzenia;
}

void Gracz::ustawZegar(Zegar* zegar)
{
	this->zegar = zegar;
}

void Gracz::ustalPredkoscPoDrabinie()
{
	double predkoscDocelowa = 0;
	if (poruszaniePoDrabinieWdol) {
		predkoscDocelowa = predkoscPoDrabinie;
	}
	else if (poruszaniePoDrabinieWgore) {
		predkoscDocelowa = -1 * predkoscPoDrabinie;
	}
	predkosc.y = predkoscDocelowa;
}
