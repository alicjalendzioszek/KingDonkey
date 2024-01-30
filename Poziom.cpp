#include "Poziom.h"
#include "World.h"


int Poziom::getNumerPoziomu()
{
	return numerPoziomu;
}

void Poziom::setNumerPoziomu(int numerPoziomu)
{
	this->numerPoziomu = numerPoziomu;
}

void Poziom::zwiekszNumerPoziomu()
{
	this->numerPoziomu++;
}

void Poziom::wyborPoziomu(World& world, Okno& okno)
{
	stworzPoziom(world, okno);
}

void Poziom::stworzPoziom(World& world, Okno& okno)
{
	if (numerPoziomu == 1) {
		stworzPoziom1(world, okno);
	}
	else if (numerPoziomu == 2) {
		stworzPoziom2(world, okno);
	}
	else if (numerPoziomu == 3)
	{
		stworzPoziom3(world, okno);
	}
}

void Poziom::inicjalizacjaDrabiny(World& world, int numerDrabiny, int pozycjaX, int pozycjaY, DlugoscDrabiny dlugosc, bool czyWPlatformie)
{
	world.getDrabiny()[numerDrabiny].setPozycja(pozycjaX, pozycjaY);
	world.getDrabiny()[numerDrabiny].setDlugosc(dlugosc);
	world.getDrabiny()[numerDrabiny].setCzyWPlatformie(czyWPlatformie);
}

void Poziom::ustawDrabinieDlugoscPlatformyWKtorejJest(World& world, int numerDrabiny, DlugoscPlatformy dlugoscPlatformyWKtorejJest)
{
	world.getDrabiny()[numerDrabiny].setDlugoscPlatformyWKtorejSieZnajduje(dlugoscPlatformyWKtorejJest);
}

void Poziom::inicjalizacjaPlatformy(World& world, int numerPlatformy, int pozycjaX, int pozycjaY, DlugoscPlatformy dlugosc)
{
	world.getPlatformy()[numerPlatformy].setPozycja(pozycjaX, pozycjaY);
	world.getPlatformy()[numerPlatformy].setDlugosc(dlugosc);
}

void Poziom::ustawienieBabyKrowy(BabyKrowa& babyKrowa, int pozycjaX, int pozycjaY)
{
	babyKrowa.setPozycja(pozycjaX, pozycjaY);
}

void Poziom::ustawienieGracza(Gracz& gracz, int pozycjaX, int pozycjaY)
{
	gracz.setPozycja(pozycjaX, pozycjaY);
	gracz.setPozycjaStartowa(pozycjaX, pozycjaY);
}

void Poziom::ustawieniePrzeciwnika(Przeciwnik& przeciwnik, int pozycjaX, int pozycjaY)
{
	przeciwnik.setPozycja(pozycjaX, pozycjaY);
}

void Poziom::ustawienieStosuBel(Bele& bele, int pozycjaX, int pozycjaY)
{
	bele.setPozycja(pozycjaX, pozycjaY);
}

void Poziom::inicjalizacjaKukurydzy(World& world, int numerKukurydzy, int pozycjaX, int pozycjaY)
{
	world.getKukurydze()[numerKukurydzy].setPozycja(pozycjaX, pozycjaY);
}

void Poziom::ustawienieBeli(Beczka& bela, int pozycjaX, int pozycjaY, double predkosc)
{
	bela.setPozycja(pozycjaX, pozycjaY);
	bela.setPozycjaStartowa(pozycjaX, pozycjaY);
	bela.setPredkoscX(predkosc);
	bela.setPredkoscStartX(predkosc);
}

void Poziom::stworzPoziom1(World& world, Okno& okno)
{
	world.setLiczbaPlatform(5);
	world.alokacjaPlatform();
	inicjalizacjaPlatformy(world, 0, platforma1Poziom1X, platforma1Poziom1Y, najdluzsza);
	inicjalizacjaPlatformy(world, 1, platforma2Poziom1X, platforma2Poziom1Y, najdluzsza);
	inicjalizacjaPlatformy(world, 2, platforma3Poziom1X, platforma3Poziom1Y, najdluzsza);
	inicjalizacjaPlatformy(world, 3, platforma4Poziom1X, platforma4Poziom1Y, najdluzsza);
	inicjalizacjaPlatformy(world, 4, platforma5Poziom1X, platforma5Poziom1Y, srednia);

	world.setLiczbaDrabin(5);
	world.alokacjaDrabin();
	inicjalizacjaDrabiny(world, 0, drabina1Poziom1X, drabina1Poziom1Y, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 0, najdluzsza);
	inicjalizacjaDrabiny(world, 1, drabina2Poziom1X, drabina2Poziom1Y, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 1, najdluzsza);
	inicjalizacjaDrabiny(world, 2, drabina3Poziom1X, drabina3Poziom1Y, dluga, false);
	inicjalizacjaDrabiny(world, 3, drabina4Poziom1X, drabina4Poziom1Y, dluga, false);
	inicjalizacjaDrabiny(world, 4, drabina5Poziom1X, drabina5Poziom1Y, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 4, najdluzsza);

	//ustalamy ustawienie pozostalych obiektow
	ustawienieGracza(world.gracz, graczPoziom1X, graczPoziom1Y); // todo bylo 726
	ustawieniePrzeciwnika(world.przeciwnik, przeciwnikPoziom1X, przeciwnikPoziom1Y);
	world.przeciwnik.setZwroconyWPrawo(true);
	ustawienieStosuBel(world.stosBel, stosBelPoziom1X, stosBelPoziom1Y);
	ustawienieBabyKrowy(world.babyKrowa, babyKrowaPoziom1X, babyKrowaPoziom1Y);

	world.setLiczbaBel(50);
	world.alokacjaBel();
	for (int i = 0; i < world.getLiczbaBel(); i++)
	{
		ustawienieBeli(world.getBele()[i], belePoziom1X, belePoziom1Y, world.getBele()->getPoczatkowaPredkosc());
		world.ustalRozmiarBeli(world.getBele()[i], okno);
	}

	//ustalamy gdzie beda bonusy sie znajdowac
	world.setLiczbaKukurydz(4);
	world.alokacjaKukurydz();
	inicjalizacjaKukurydzy(world, 0, kukurydza1Poziom1X, kukurydza1Poziom1Y);
	inicjalizacjaKukurydzy(world, 1, kukurydza2Poziom1X, kukurydza2Poziom1Y);
	inicjalizacjaKukurydzy(world, 2, kukurydza3Poziom1X, kukurydza3Poziom1Y);
	inicjalizacjaKukurydzy(world, 3, kukurydza4Poziom1X, kukurydza4Poziom1Y);

	//ustalenie rozmiarow tych przemdiotow ktorych rozmiary sie nie zmieniaja w trakcie rozgrywki
	world.ustalRozmiarBabyKrowy(okno);

	for (int i = 0; i < world.getLiczbaKukurydz(); i++)
	{
		world.ustalRozmiarKukurydzy(world.getKukurydze()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaPlatform(); i++)
	{
		world.ustalRozmiarPlatformy(world.getPlatformy()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaDrabin(); i++)
	{
		world.ustalRozmiarDrabiny(world.getDrabiny()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaDrabin(); i++)
	{
		world.ustalRozmiarPlatformyWKtorejJestDrabina(world.getDrabiny()[i], okno);
	}
}


void Poziom::stworzPoziom2(World& world, Okno& okno)
{
	world.setLiczbaPlatform(9);
	world.alokacjaPlatform();
	inicjalizacjaPlatformy(world, 0, platforma1Poziom2X, platforma1Poziom2Y, srednia);
	inicjalizacjaPlatformy(world, 1, platforma2Poziom2X, platforma2Poziom2Y, srednia);
	inicjalizacjaPlatformy(world, 2, platforma3Poziom2X, platforma3Poziom2Y, srednia);
	inicjalizacjaPlatformy(world, 3, platforma4Poziom2X, platforma4Poziom2Y, srednia);
	inicjalizacjaPlatformy(world, 4, platforma5Poziom2X, platforma5Poziom2Y, srednia);
	inicjalizacjaPlatformy(world, 5, platforma6Poziom2X, platforma6Poziom2Y, srednia);
	inicjalizacjaPlatformy(world, 6, platforma7Poziom2X, platforma7Poziom2Y, srednia);
	inicjalizacjaPlatformy(world, 7, platforma8Poziom2X, platforma8Poziom2Y, najdluzsza);
	inicjalizacjaPlatformy(world, 8, platforma9Poziom2X, platforma9Poziom2Y, najdluzsza);

	world.setLiczbaDrabin(6);
	world.alokacjaDrabin();
	inicjalizacjaDrabiny(world, 0, drabina1Poziom2X, drabina1Poziom2Y, krotka, false);
	inicjalizacjaDrabiny(world, 1, drabina2Poziom2X, drabina2Poziom2Y, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 1, srednia);
	inicjalizacjaDrabiny(world, 2, drabina3Poziom2X, drabina3Poziom2Y, krotka, false);
	inicjalizacjaDrabiny(world, 3, drabina4Poziom2X, drabina4Poziom2Y, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 3, srednia);
	inicjalizacjaDrabiny(world, 4, drabina5Poziom2X, drabina5Poziom2Y, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 4, srednia);
	inicjalizacjaDrabiny(world, 5, drabina6Poziom2X, drabina6Poziom2Y, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 5, srednia);

	//ustalamy ustawienie pozostalych obiektow
	ustawienieGracza(world.gracz , graczPoziom2X, graczPoziom2Y);//735
	ustawieniePrzeciwnika(world.przeciwnik, przeciwnikPoziom2X, przeciwnikPoziom2Y);
	world.przeciwnik.setZwroconyWPrawo(false);
	ustawienieStosuBel(world.stosBel, stosBelPoziom2X, stosBelPoziom2Y);
	ustawienieBabyKrowy(world.babyKrowa, babyKrowaPoziom2X, babyKrowaPoziom2Y);
	
	world.setLiczbaBel(50);
	world.alokacjaBel();
	for (int i = 0; i < world.getLiczbaBel(); i++)
	{
		ustawienieBeli(world.getBele()[i], belePoziom2X, belePoziom2Y, -world.getBele()->getPoczatkowaPredkosc());
		world.ustalRozmiarBeli(world.getBele()[i], okno);
	}


	world.setLiczbaKukurydz(6);
	world.alokacjaKukurydz();
	inicjalizacjaKukurydzy(world, 0, kukurydza1Poziom2X, kukurydza1Poziom2Y);
	inicjalizacjaKukurydzy(world, 1, kukurydza2Poziom2X, kukurydza2Poziom2Y);
	inicjalizacjaKukurydzy(world, 2, kukurydza3Poziom2X, kukurydza3Poziom2Y);
	inicjalizacjaKukurydzy(world, 3, kukurydza4Poziom2X, kukurydza4Poziom2Y);
	inicjalizacjaKukurydzy(world, 4, kukurydza5Poziom2X, kukurydza5Poziom2Y);
	inicjalizacjaKukurydzy(world, 5, kukurydza6Poziom2X, kukurydza6Poziom2Y);

	//ustalenie rozmiarow
	world.ustalRozmiarBabyKrowy(okno);

	for (int i = 0; i < world.getLiczbaKukurydz(); i++)
	{
		world.ustalRozmiarKukurydzy(world.getKukurydze()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaPlatform(); i++)
	{
		world.ustalRozmiarPlatformy(world.getPlatformy()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaDrabin(); i++)
	{
		world.ustalRozmiarDrabiny(world.getDrabiny()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaDrabin(); i++)
	{
		world.ustalRozmiarPlatformyWKtorejJestDrabina(world.getDrabiny()[i], okno);
	}

}

void Poziom::stworzPoziom3(World& world, Okno& okno)
{
	world.setLiczbaPlatform(14);
	world.alokacjaPlatform();
	inicjalizacjaPlatformy(world, 0, platforma1Poziom3X, platforma1Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 1, platforma2Poziom3X, platforma2Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 2, platforma3Poziom3X, platforma3Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 3, platforma4Poziom3X, platforma4Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 4, platforma5Poziom3X, platforma5Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 5, platforma6Poziom3X, platforma6Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 6, platforma7Poziom3X, platforma7Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 7, platforma8Poziom3X, platforma8Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 8, platforma9Poziom3X, platforma9Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 9, platforma10Poziom3X, platforma10Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 10, platforma11Poziom3X, platforma11Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 11, platforma12Poziom3X, platforma12Poziom3Y, najkrotsza);
	inicjalizacjaPlatformy(world, 12, platforma13Poziom3X, platforma13Poziom3Y, srednia);
	inicjalizacjaPlatformy(world, 13, platforma14Poziom3X, platforma14Poziom3Y, najkrotsza);

	world.setLiczbaDrabin(8);
	world.alokacjaDrabin();
	inicjalizacjaDrabiny(world, 0, drabina1Poziom3X, drabina1Poziom3Y, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 0, najkrotsza);
	inicjalizacjaDrabiny(world, 1, drabina2Poziom3X, drabina2Poziom3Y, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 1, najkrotsza);
	inicjalizacjaDrabiny(world, 2, drabina3Poziom3X, drabina3Poziom3Y, krotka, true);//w 
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 2, najkrotsza);
	inicjalizacjaDrabiny(world, 3, drabina4Poziom3X, drabina4Poziom3Y, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 3, najkrotsza);
	inicjalizacjaDrabiny(world, 4, drabina5Poziom3X, drabina5Poziom3Y, dluga, false);
	inicjalizacjaDrabiny(world, 5, drabina6Poziom3X, drabina6Poziom3Y, dluga, false);
	inicjalizacjaDrabiny(world, 6, drabina7Poziom3X, drabina7Poziom3Y, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 6, najkrotsza);
	inicjalizacjaDrabiny(world, 7, drabina8Poziom3X, drabina8Poziom3Y, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 7, najkrotsza);

	//ustalamy ustawienie pozostalych obiektow
	ustawienieGracza(world.gracz, graczPoziom3X, graczPoziom3Y);
	ustawieniePrzeciwnika(world.przeciwnik, przeciwnikPoziom3X, przeciwnikPoziom3Y);
	world.przeciwnik.setZwroconyWPrawo(false);
	//world.przeciwnik.zwroconyWPrawo = false;
	ustawienieStosuBel(world.stosBel, stosBelPoziom3X, stosBelPoziom3Y);
	ustawienieBabyKrowy(world.babyKrowa, babyKrowaPoziom3X, babyKrowaPoziom3Y);

	//ustalenie rozmiarow
	world.setLiczbaBel(50);
	world.alokacjaBel();
	for (int i = 0; i < world.getLiczbaBel(); i++)
	{
		ustawienieBeli(world.getBele()[i], belePoziom3X, belePoziom3Y, -world.getBele()->getPoczatkowaPredkosc());
		world.ustalRozmiarBeli(world.getBele()[i], okno);
	}


	world.setLiczbaKukurydz(9);
	world.alokacjaKukurydz();
	inicjalizacjaKukurydzy(world, 0, kukurydza1Poziom3X, kukurydza1Poziom3Y);
	inicjalizacjaKukurydzy(world, 1, kukurydza2Poziom3X, kukurydza2Poziom3Y);
	inicjalizacjaKukurydzy(world, 2, kukurydza3Poziom3X, kukurydza3Poziom3Y);
	inicjalizacjaKukurydzy(world, 3, kukurydza4Poziom3X, kukurydza4Poziom3Y);
	inicjalizacjaKukurydzy(world, 4, kukurydza5Poziom3X, kukurydza5Poziom3Y);
	inicjalizacjaKukurydzy(world, 5, kukurydza6Poziom3X, kukurydza6Poziom3Y);
	inicjalizacjaKukurydzy(world, 6, kukurydza7Poziom3X, kukurydza7Poziom3Y);
	inicjalizacjaKukurydzy(world, 7, kukurydza8Poziom3X, kukurydza8Poziom3Y);
	inicjalizacjaKukurydzy(world, 8, kukurydza9Poziom3X, kukurydza9Poziom3Y);

	//ustalanie rozmiarow
	world.ustalRozmiarBabyKrowy(okno);

	for (int i = 0; i < world.getLiczbaKukurydz(); i++)
	{
		world.ustalRozmiarKukurydzy(world.getKukurydze()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaPlatform(); i++)
	{
		world.ustalRozmiarPlatformy(world.getPlatformy()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaDrabin(); i++)
	{
		world.ustalRozmiarDrabiny(world.getDrabiny()[i], okno);
	}

	for (int i = 0; i < world.getLiczbaDrabin(); i++)
	{
		world.ustalRozmiarPlatformyWKtorejJestDrabina(world.getDrabiny()[i], okno);
	}
}
