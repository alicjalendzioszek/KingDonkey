#include "Gracz.h"
#include "wymiaryOkna.h"
//#include "Gracz.h"
//#define SCREEN_WIDTH	1400
//#define SCREEN_HEIGHT	800

Gracz::Gracz()
{
}

XY Gracz::getPozycja()
{
	return pozycja;
}

XY Gracz::getRozmiar()
{
	return rozmiar;
}

XY Gracz::getPredkosc()
{
	return predkosc;
}

bool Gracz::getCzyNaDrabinie()
{
	return czyNaDrabinie;
}

bool Gracz::getCzyDodanoPunktyZaSkok()
{
	return czyDodanoPunktyZaSkok;
}

int Gracz::getLiczbaPunktowGracza()
{
	return liczbaPunktowGracza;
}

int Gracz::getNumerKlatkiPion()
{
	return numerKlatkiPion;
}

int Gracz::getNumerKlatkiPoziom()
{
	return numerKlatkiPoziom;
}

bool Gracz::getCzyRuchWPrawo()
{
	return czyRuchWPrawo;
}

double Gracz::getPredkoscRuchu()
{
	return predkoscRuchu;
}

bool Gracz::getCzyAnimacjaPunktowZaSkok()
{
	return czyAnimacjaPunktowZaSkok;
}

bool Gracz::getCzyAnimacjaPunktowZaZebranieBonusa()
{
	return czyAnimacjaPunktowZaZebranieBonusa;
}

double Gracz::getPrzesuniecieZderzenia()
{
	return przesuniecieZderzenia;
}

void Gracz::setCzyAnimacjaPunktowZaSkok(bool animacjaPunktowSkok)
{
	this->czyAnimacjaPunktowZaSkok = animacjaPunktowSkok;
}

void Gracz::setCzyAnimacjaPunktowZaZebranieBonusa(bool animacjaPunktowBonus)
{
	this->czyAnimacjaPunktowZaZebranieBonusa = animacjaPunktowBonus;
}

void Gracz::setCzyRuchDoDolu(bool czyDoDolu)
{
	this->czyRuchDoDolu = czyDoDolu;
}

void Gracz::zmniejszLiczbePunktowGracza(int liczbaPunktow)
{
	this->liczbaPunktowGracza -= liczbaPunktow;
}

void Gracz::setCzyNaDrabinie(bool naDrabinie)
{
	this->czyNaDrabinie = naDrabinie;
}

void Gracz::setPozycjaX(double x)
{
	this->pozycja.x = x;
}

void Gracz::setPozycjaY(double y)
{
	this->pozycja.y = y;
}

void Gracz::setCzySpada(bool spada)
{
	this->czySpada = spada;
}

void Gracz::setCzySkoczyl(bool czySkoczyl)
{
	this->czySkoczyl = czySkoczyl;
}

void Gracz::setCzyDodanoPunktyZaSkok(bool czyPunktyZaSkok)
{
	this->czyDodanoPunktyZaSkok=czyPunktyZaSkok;
}

void Gracz::setPoruszaniePoDrabinieWGore(bool wGore)
{
	this->poruszaniePoDrabinieWGore = wGore;
}

void Gracz::setPoruszaniePoDrabinieWDol(bool wDol)
{
	this->poruszaniePoDrabinieWDol = wDol;
}

void Gracz::setPredkoscX(double predkoscX)
{
	this->predkosc.x = predkoscX;
}

void Gracz::setPredkoscY(double predkoscY)
{
	this->predkosc.y = predkoscY;
}

void Gracz::setCzyRuchWPrawo(bool wPrawo)
{
	this->czyRuchWPrawo = wPrawo;
}

void Gracz::setPozycja(double x, double y)
{
	this->pozycja.x = x;
	this->pozycja.y = y;
}

void Gracz::setPozycjaStartowa(double x, double y)
{
	this->pozycjaStartowa.x = x;
	this->pozycjaStartowa.y = y;
}

void Gracz::setRozmiar(double x, double y)
{
	this->rozmiar.x = x;
	this->rozmiar.y = y;
}

void Gracz::zwiekszLiczbePunktowGracza(int liczbaPunktow)
{
	this->liczbaPunktowGracza += liczbaPunktow;
}

void Gracz::setLiczbaPunktowGracza(int liczbaPunktow)
{
	this->liczbaPunktowGracza = liczbaPunktow;
}

void Gracz::zwiekszNumerKlatkiPion()
{
	this->numerKlatkiPion++;
}

void Gracz::zwiekszNumerKlatkiPoziom()
{
	this->numerKlatkiPoziom++;
}

void Gracz::setNumerKlatkiPion(int numer)
{
	this->numerKlatkiPion = numer;
}

void Gracz::setNumerKlatkiPoziom(int numer)
{
	this->numerKlatkiPoziom = numer;
}

void Gracz::zaaktualizujPozycje()
{
	auto delte = zegar->getDelta();

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
	if (poruszaniePoDrabinieWDol) {
		predkoscDocelowa = predkoscPoDrabinie;
	}
	else if (poruszaniePoDrabinieWGore) {
		predkoscDocelowa = -1 * predkoscPoDrabinie;
	}
	predkosc.y = predkoscDocelowa;
}
