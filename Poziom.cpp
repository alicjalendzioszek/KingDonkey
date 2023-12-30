#include "Poziom.h"
#include "World.h"


void Poziom::wyborPoziomu(World& world, Gracz& gracz)
{

	// todo
	numerPoziomu = 1;
	stworzPoziom(world, gracz);
}

void Poziom::stworzPoziom(World& world, Gracz& gracz)
{
	if (numerPoziomu == 1) {
		stworzPoziom1(world, gracz);
	}
	else if (numerPoziomu == 2) {
		//stworzPoziom1(world, gracz);
	}
	else if (numerPoziomu == 3)
	{
		//stworzPoziom3(world, gracz);
	}
}

void Poziom::stworzPoziom1(World& world, Gracz& gracz)
{
	world.liczbaPlatform = 5;
	for (int i = 0; i < world.liczbaPlatform; i++)
	{
		world.platformy[i].pozycja.x = 0;//todo
	}
}
