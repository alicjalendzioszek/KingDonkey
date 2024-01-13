#include "Poziom.h"
#include "World.h"


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
	world.drabiny[numerDrabiny].pozycja.x = pozycjaX;
	world.drabiny[numerDrabiny].pozycja.y = pozycjaY;
	world.drabiny[numerDrabiny].dlugosc = dlugosc;
	world.drabiny[numerDrabiny].czyWPlatformie = czyWPlatformie;
}

void Poziom::ustawDrabinieDlugoscPlatformyWKtorejJest(World& world, int numerDrabiny, DlugoscPlatformy dlugoscPlatformyWKtorejJest)
{
	world.drabiny[numerDrabiny].dlugoscPlatformyWKtorejSieZnajduje = dlugoscPlatformyWKtorejJest;
}

void Poziom::inicjalizacjaPlatformy(World& world, int numerPlatformy, int pozycjaX, int pozycjaY, DlugoscPlatformy dlugosc)
{
	world.platformy[numerPlatformy].pozycja.x = pozycjaX;
	world.platformy[numerPlatformy].pozycja.y = pozycjaY;
	world.platformy[numerPlatformy].dlugosc = dlugosc;
}

void Poziom::ustawienieBabyKrowy(BabyKrowa& babyKrowa, int pozycjaX, int pozycjaY)
{
	babyKrowa.pozycja.x = pozycjaX;
	babyKrowa.pozycja.y = pozycjaY;
}

void Poziom::ustawienieGracza(Gracz& gracz, int pozycjaX, int pozycjaY)
{
	gracz.pozycja.x = pozycjaX;
	gracz.pozycja.y = pozycjaY;
	gracz.pozycjaStartowa.x = pozycjaX;
	gracz.pozycjaStartowa.y = pozycjaY;
}

void Poziom::ustawieniePrzeciwnika(Przeciwnik& przeciwnik, int pozycjaX, int pozycjaY)
{
	przeciwnik.pozycja.x = pozycjaX;
	przeciwnik.pozycja.y = pozycjaY;
}

void Poziom::ustawienieStosuBel(Bele& bele, int pozycjaX, int pozycjaY)
{
	bele.pozycja.x = pozycjaX;
	bele.pozycja.y = pozycjaY;
}

void Poziom::inicjalizacjaKukurydzy(World& world, int numerKukurydzy, int pozycjaX, int pozycjaY)
{
	world.kukurydze[numerKukurydzy].pozycja.x = pozycjaX;
	world.kukurydze[numerKukurydzy].pozycja.y = pozycjaY;
}

void Poziom::ustawienieBeli(Beczka& bela, int pozycjaX, int pozycjaY,double predkosc)
{
	bela.pozycja.x = pozycjaX;
	bela.pozycja.y = pozycjaY;
	bela.pozycjaStartowa.x = pozycjaX;
	bela.pozycjaStartowa.y = pozycjaY;
	bela.predkosc.x = predkosc;
	bela.predkoscStart.x = predkosc;
}

void Poziom::stworzPoziom1(World& world, Okno& okno)
{
	world.liczbaPlatform = 5;
	world.alokacjaPlatform();
	inicjalizacjaPlatformy(world, 0, 700, 760, najdluzsza);
	inicjalizacjaPlatformy(world, 1, 820, 600, najdluzsza);
	inicjalizacjaPlatformy(world, 2, 600, 500, najdluzsza);
	inicjalizacjaPlatformy(world, 3, 870, 300, najdluzsza);
	inicjalizacjaPlatformy(world, 4, 1050, 132, srednia);

	world.liczbaDrabin = 5;
	world.alokacjaDrabin();
	inicjalizacjaDrabiny(world, 0, 370, 680, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 0, najdluzsza);
	inicjalizacjaDrabiny(world, 1, 1130, 680, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 1, najdluzsza);
	inicjalizacjaDrabiny(world, 2, 430, 380, dluga, false);
	inicjalizacjaDrabiny(world, 3, 1000, 380, dluga, false);
	inicjalizacjaDrabiny(world, 4, 880, 220, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 4, najdluzsza);
	//inicjalizacjaDrabiny(world, 5, 600, 540, krotka);

	//ustalamy ustawienie pozostalych obiektow
	ustawienieGracza(world.gracz, 700, 725); // todo bylo 726
	ustawieniePrzeciwnika(world.przeciwnik, 1150, 220);
	world.przeciwnik.zwroconyWPrawo = true;
	ustawienieStosuBel(world.stosBel, 1300, 215);
	ustawienieBabyKrowy(world.babyKrowa, 1200, 98);

	world.liczbaBel = 50;
	world.alokacjaBel();
	for (int i = 0; i < world.liczbaBel; i++)
	{
		ustawienieBeli(world.bele[i], 1090, 245, world.bele->poczatkowaPredkosc);
		world.ustalRozmiarBeli(world.bele[i], okno);
	}

	//ustalamy gdzie beda bonusy sie znajdowac
	world.liczbaKukurydz = 4;
	world.alokacjaKukurydz();
	inicjalizacjaKukurydzy(world,0,260,723);
	inicjalizacjaKukurydzy(world,1,820,563);
	inicjalizacjaKukurydzy(world,2,200,463);
	inicjalizacjaKukurydzy(world, 3,650,263);


	//ustalenie rozmiarow tych przemdiotow ktorych rozmiary sie nie zmieniaja w trakcie rozgrywki
	for (int i = 0; i < world.liczbaKukurydz; i++)
	{
		world.ustalRozmiarKukurydzy(world.kukurydze[i], okno);
	}

	for (int i = 0; i < world.liczbaPlatform; i++)
	{
		world.ustalRozmiarPlatformy(world.platformy[i], okno);
	}

	for (int i = 0; i < world.liczbaDrabin; i++)
	{
		world.ustalRozmiarDrabiny(world.drabiny[i], okno);
	}

	world.ustalRozmiarBabyKrowy(okno);
	for (int i = 0; i < world.liczbaDrabin; i++)
	{
		world.ustalRozmiarPlatformyWKtorejJestDrabina(world.drabiny[i], okno);
	}
}


void Poziom::stworzPoziom2(World& world, Okno& okno)
{
	world.liczbaPlatform = 9;
	world.alokacjaPlatform();
	inicjalizacjaPlatformy(world, 0, 600, 93, srednia);
	inicjalizacjaPlatformy(world, 1, 320, 771, srednia);
	inicjalizacjaPlatformy(world, 2, 510, 674, srednia);
	inicjalizacjaPlatformy(world, 3, 1020, 675, srednia);
	inicjalizacjaPlatformy(world, 4, 1200, 390, srednia);
	inicjalizacjaPlatformy(world, 5, 700, 378, srednia);
	inicjalizacjaPlatformy(world, 6, 200, 390, srednia);
	inicjalizacjaPlatformy(world, 7, 700, 508, najdluzsza);
	inicjalizacjaPlatformy(world, 8, 550, 223, najdluzsza);

	world.liczbaDrabin = 6;
	world.alokacjaDrabin();
	inicjalizacjaDrabiny(world, 0, 650, 142, krotka, false);
	inicjalizacjaDrabiny(world, 1, 450, 723, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 1, srednia);
	inicjalizacjaDrabiny(world, 2, 700, 427, krotka, false);
	inicjalizacjaDrabiny(world, 3, 1070, 588, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 3, srednia);
	inicjalizacjaDrabiny(world, 4, 350, 303, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 4, srednia);
	inicjalizacjaDrabiny(world, 5, 1020, 303, dluga, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 5, srednia);

	//ustalamy ustawienie pozostalych obiektow
	ustawienieGracza(world.gracz, 370, 735);//735
	ustawieniePrzeciwnika(world.przeciwnik, 257, 143);
	world.przeciwnik.zwroconyWPrawo = false;
	ustawienieStosuBel(world.stosBel, 125, 138);
	ustawienieBabyKrowy(world.babyKrowa, 500, 59);
	//ustalenie rozmiarow

	world.liczbaBel = 50;
	world.alokacjaBel();
	for (int i = 0; i < world.liczbaBel; i++)
	{
		ustawienieBeli(world.bele[i], 317, 168,-world.bele->poczatkowaPredkosc);
		world.ustalRozmiarBeli(world.bele[i], okno);
	}


	world.liczbaKukurydz = 6;
	world.alokacjaKukurydz();
	inicjalizacjaKukurydzy(world, 0, 260, 742);
	inicjalizacjaKukurydzy(world, 1, 900, 646);
	inicjalizacjaKukurydzy(world, 2, 570, 645);
	inicjalizacjaKukurydzy(world, 3, 1300, 361);
	inicjalizacjaKukurydzy(world, 4, 50, 361);
	inicjalizacjaKukurydzy(world, 5, 260, 471);

	for (int i = 0; i < world.liczbaKukurydz; i++)
	{
		world.ustalRozmiarKukurydzy(world.kukurydze[i], okno);
	}

	for (int i = 0; i < world.liczbaPlatform; i++)
	{
		world.ustalRozmiarPlatformy(world.platformy[i], okno);
	}

	for (int i = 0; i < world.liczbaDrabin; i++)
	{
		world.ustalRozmiarDrabiny(world.drabiny[i], okno);
	}

	for (int i = 0; i < world.liczbaDrabin; i++)
	{
		world.ustalRozmiarPlatformyWKtorejJestDrabina(world.drabiny[i], okno);
	}

	/*for (int i = 0; i < world.liczbaPlatform; i++)
	{
		if (world.gracz.pozycja.y + world.gracz.rozmiar.y < world.platformy[i].pozycja.y - world.platformy[i].rozmiar.y)
		{
			world.platformy[i].czyGraczZnajdujeSieNad = true;
		}
		else
		{
			world.platformy[i].czyGraczZnajdujeSieNad = false;
		}
	}*/


}

void Poziom::stworzPoziom3(World& world, Okno& okno)
{
	world.liczbaPlatform = 14;
	world.alokacjaPlatform();
	inicjalizacjaPlatformy(world, 0, 700, 770, najkrotsza);
	inicjalizacjaPlatformy(world, 1, 855, 673, najkrotsza);
	inicjalizacjaPlatformy(world, 2, 855, 279, najkrotsza);
	inicjalizacjaPlatformy(world, 3, 545, 673, najkrotsza);
	inicjalizacjaPlatformy(world, 4, 545, 279, najkrotsza);

	inicjalizacjaPlatformy(world, 5, 700, 279, najkrotsza);

	inicjalizacjaPlatformy(world, 6, 390, 576, najkrotsza);
	inicjalizacjaPlatformy(world, 7, 390, 376, najkrotsza);
	inicjalizacjaPlatformy(world, 8, 1010, 576, najkrotsza);
	inicjalizacjaPlatformy(world, 9, 1010, 376, najkrotsza);
	inicjalizacjaPlatformy(world, 10, 1165, 470, najkrotsza);
	inicjalizacjaPlatformy(world, 11, 235, 470, najkrotsza);
	inicjalizacjaPlatformy(world, 12, 440, 170, srednia);
	inicjalizacjaPlatformy(world, 13, 850, 110, najkrotsza);

	world.liczbaDrabin = 8;
	world.alokacjaDrabin();
	inicjalizacjaDrabiny(world, 0, 777, 722, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 0, najkrotsza);
	inicjalizacjaDrabiny(world, 1, 623, 722, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 1, najkrotsza);
	inicjalizacjaDrabiny(world, 2, 932, 625, krotka, true);//w 
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 2, najkrotsza);
	inicjalizacjaDrabiny(world, 3, 468, 625, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 3, najkrotsza);
	//inicjalizacjaDrabiny(world, 4, 313, 520, krotka);
	inicjalizacjaDrabiny(world, 4, 313, 464, dluga, false);
	//inicjalizacjaDrabiny(world, 5, 313, 420, krotka);
	//inicjalizacjaDrabiny(world, 6, 1087, 520, krotka);
	inicjalizacjaDrabiny(world, 5, 1087, 464, dluga, false);
	//inicjalizacjaDrabiny(world, 7, 1087, 420, krotka);
	inicjalizacjaDrabiny(world, 6, 933, 328, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 6, najkrotsza);
	inicjalizacjaDrabiny(world, 7, 468, 328, krotka, true);//w
	ustawDrabinieDlugoscPlatformyWKtorejJest(world, 7, najkrotsza);

	//ustalamy ustawienie pozostalych obiektow
	ustawienieGracza(world.gracz, 700, 734);
	ustawieniePrzeciwnika(world.przeciwnik, 450, 98);
	world.przeciwnik.zwroconyWPrawo = false;
	ustawienieStosuBel(world.stosBel, 320, 93);
	ustawienieBabyKrowy(world.babyKrowa, 890, 76);

	//ustalenie rozmiarow
	world.liczbaBel = 50;
	world.alokacjaBel();
	for (int i = 0; i < world.liczbaBel; i++)
	{
		ustawienieBeli(world.bele[i], 510, 123,-world.bele->poczatkowaPredkosc);
		world.ustalRozmiarBeli(world.bele[i], okno);
	}


	world.liczbaKukurydz = 9;
	world.alokacjaKukurydz();
	inicjalizacjaKukurydzy(world, 0, 855, 644);
	inicjalizacjaKukurydzy(world, 1, 545, 644);
	inicjalizacjaKukurydzy(world, 2, 390, 547);
	inicjalizacjaKukurydzy(world, 3, 1010, 547);
	inicjalizacjaKukurydzy(world, 4, 1165, 441);
	inicjalizacjaKukurydzy(world, 5, 235, 441);
	inicjalizacjaKukurydzy(world, 6, 1010, 347);
	inicjalizacjaKukurydzy(world, 7, 390, 347);
	inicjalizacjaKukurydzy(world, 8, 700, 250);

	for (int i = 0; i < world.liczbaKukurydz; i++)
	{
		world.ustalRozmiarKukurydzy(world.kukurydze[i], okno);
	}


	for (int i = 0; i < world.liczbaPlatform; i++)
	{
		world.ustalRozmiarPlatformy(world.platformy[i], okno);
	}

	for (int i = 0; i < world.liczbaDrabin; i++)
	{
		world.ustalRozmiarDrabiny(world.drabiny[i], okno);
	}

	for (int i = 0; i < world.liczbaDrabin; i++)
	{
		world.ustalRozmiarPlatformyWKtorejJestDrabina(world.drabiny[i], okno);
	}
}
