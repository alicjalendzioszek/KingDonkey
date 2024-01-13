#pragma once
#include "struktury.h"
//class Gracz;
//class Beczka;



void aktualizacjaPozycji(XY& pozycja, XY& predkosc, double czas) {
	pozycja.x = pozycja.x + (predkosc.x * czas);
	pozycja.y = pozycja.y + (predkosc.y * czas);
}

//bool czyKolizja(Gracz& gracz, Beczka& bela)
//{
//	//najpierw sprawdzamy czy prawa krawedz, srodek lub lewa krawedz gracza znajduje sie wewnatrz beli (dotyka jej)
//	if ((gracz.wezX1Zderzen() <= bela.wezX2Zderzen() && gracz.wezX1Zderzen() >= bela.wezX1Zderzen())
//		|| (gracz.wezX2Zderzen() <= bela.wezX2Zderzen() && gracz.wezX2Zderzen() >= bela.wezX1Zderzen())
//		|| (gracz.pozycja.x <= bela.wezX2Zderzen() && gracz.pozycja.x >= bela.wezX1Zderzen()))
//	{
//		//sprawdzamy czy gorna krawedz lub dolna krawedz gracza znajduje sie wewnatrz beli (dotyka jej)
//		if ((gracz.wezY1Zderzen() <= bela.wezY2Zderzen() && gracz.wezY1Zderzen() >= bela.wezY1Zderzen())
//			|| (gracz.wezY2Zderzen() <= bela.wezY2Zderzen() && gracz.wezY2Zderzen() >= bela.wezY1Zderzen()))
//		{
//			return true;
//		}
//	}
//	return false;
//}

//bool czyKolizja(XY& pozycja1, XY& pozycja2) {
//
//	// todo
//	if()
//	return false;
//}