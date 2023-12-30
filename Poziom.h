#pragma once


class World;
class Gracz;

class Poziom {
public:

	int numerPoziomu = 0;

	void wyborPoziomu(World& world, Gracz& gracz);

	void stworzPoziom(World& world, Gracz& gracz);

	// ustalic ilosc beczke, ramp i ich pozycje oraz pozycje gracza dla kazdego z poziomow
	void stworzPoziom1(World& world, Gracz& gracz);

	/*void stworzPoziom2(World& world, Gracz& gracz);

	void stworzPoziom3(World& world, Gracz& gracz);*/

};
