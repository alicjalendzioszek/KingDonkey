#pragma once

#include "Event.h"
#include "Zegar.h"
#include "Gracz.h"
#include "Beczka.h"
#include "Okno.h"
#include "Platforma.h"
#include "Poziom.h"



class World
{
public:

	Event event;
	Poziom poziom;
	Zegar zegar;
	Gracz gracz;

	int liczbaBeczek = 0;
	Beczka* beczki = nullptr;

	int liczbaPlatform = 0;
	Platforma* platformy = nullptr;

	bool czyKoniecPoziomu = 0;


	void utworzSwiat();

	void wykonajTure(Okno& okno);

	void zaktualizujSwiat();


	void sprawdzCzySpada();

	bool sprawdzCzyNaDrabinie();

	void sprawdzCzyGraczSpada();

	void sprawdzKolizjeZBeczkami();

	void sprawdzKolizjeGracza();

};

