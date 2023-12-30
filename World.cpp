#include "World.h"

void World::utworzSwiat()
{
	poziom.wyborPoziomu(*this, gracz);
}

void World::wykonajTure(Okno& okno)
{
	event.readEvents(*this, okno);
	zaktualizujSwiat();
}

void World::zaktualizujSwiat()
{
	for (int i = 0; i < liczbaBeczek; i++) {
		if (beczki[i].czyAktywna == true) {
			beczki[i].zaaktualizujPozycje();
		}
	}

	if (sprawdzCzyNaDrabinie() == false) {
		sprawdzCzySpada();
	}

	gracz.zaaktualizujPozycje();

	sprawdzKolizjeGracza();

}

void World::sprawdzCzySpada()
{
	// sprawdza czy pod nim sa rampy albo zerowa podloga
}

bool World::sprawdzCzyNaDrabinie()
{
	// sprawdzic kolizje gracz z wszystkimi drabinami
		// jesli false ustal predkosc.y = 0;
		// return false;

	return true;
}

void World::sprawdzCzyGraczSpada()
{
	// sprawdz czy gracz ma pod soba rampe lub podloge

	gracz.czySpada = false;
}

void World::sprawdzKolizjeZBeczkami()
{
	for (int i = 0; i < liczbaBeczek; i++) {
		if (beczki[i].czyAktywna == true) {
			bool kolizja = czyKolizja(beczki[i].pozycja, gracz.pozycja);

			if (kolizja) {
				// todo gracz traci zycie czy cos


			}
		}
	}
}

void World::sprawdzKolizjeGracza()
{
	sprawdzKolizjeZBeczkami();
	sprawdzCzyGraczSpada();
}
