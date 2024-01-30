#pragma once
#include "struktury.h"
#include "Zegar.h"

class Gracz
{
private:
	XY pozycja;
	XY pozycjaStartowa;
	XY predkosc;
	XY rozmiar;
	Zegar* zegar = nullptr;

	bool czySkoczyl = false;
	bool czySpada = false;
	bool czyNaDrabinie = false;
	bool czyRuchWPrawo = false;
	bool czyRuchDoDolu = false;
	bool czyAnimacjaSkoku = false;
	bool czyDodanoPunktyZaSkok = false;
	bool czyAnimacjaPunktowZaSkok = false;
	bool czyAnimacjaPunktowZaZebranieBonusa = false;
	bool poruszaniePoDrabinieWGore = false;
	bool poruszaniePoDrabinieWDol = false;

	int liczbaPunktowGracza = 0;
	int numerKlatkiPion = 0;
	int numerKlatkiPoziom = 0;
	int numerKlatkiPunkty = 0;
	
	const double predkoscZmianyWSpadku = 700;
	const double predkoscSkoku = -400;
	const double predkoscRuchu = 200;
	const double predkoscPoDrabinie = 200;
	const double przesuniecieZderzenia = 1.0;
public:

	Gracz();

	//gettery
	XY getPozycja();
	XY getRozmiar();
	XY getPredkosc();
	bool getCzyNaDrabinie();
	bool getCzyDodanoPunktyZaSkok();
	bool getCzyRuchWPrawo();
	bool getCzyAnimacjaPunktowZaSkok();
	bool getCzyAnimacjaPunktowZaZebranieBonusa();
	int getLiczbaPunktowGracza();
	int getNumerKlatkiPion();
	int getNumerKlatkiPoziom();
	double getPredkoscRuchu();
	double getPrzesuniecieZderzenia();

	//settery
	void setCzyAnimacjaPunktowZaSkok(bool animacjaPunktowSkok);
	void setCzyAnimacjaPunktowZaZebranieBonusa(bool animacjaPunktowBonus);
	void setCzyRuchDoDolu(bool czyDoDolu);
	void setCzyNaDrabinie(bool naDrabinie);
	void setPozycjaX(double x);
	void setPozycjaY(double y);
	void setCzySpada(bool spada);
	void setCzySkoczyl(bool czySkoczyl);
	void setCzyDodanoPunktyZaSkok(bool czyPunktyZaSkok);
	void setPoruszaniePoDrabinieWGore(bool wGore);
	void setPoruszaniePoDrabinieWDol(bool wDol);
	void setPredkoscX(double predkoscX);
	void setPredkoscY(double predkoscY);
	void setCzyRuchWPrawo(bool wPrawo);
	void setPozycja(double x, double y);
	void setPozycjaStartowa(double x, double y);
	void setRozmiar(double x, double y);
	void setLiczbaPunktowGracza(int liczbaPunktow);
	void setNumerKlatkiPion(int numer);
	void setNumerKlatkiPoziom(int numer);

	void zwiekszLiczbePunktowGracza(int liczbaPunktow);
	void zmniejszLiczbePunktowGracza(int liczbaPunktow);
	void zwiekszNumerKlatkiPion();
	void zwiekszNumerKlatkiPoziom();

	void zaaktualizujPozycje();
	void ustawZegar(Zegar* zegar);
	void ustalPredkoscPoDrabinie();

	double wezX1Zderzen();
	double wezX2Zderzen();
	double wezY1Zderzen();
	double wezY2Zderzen();

};

