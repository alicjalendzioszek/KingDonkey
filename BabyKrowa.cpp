#include "BabyKrowa.h"

double BabyKrowa::wezX1Zderzen()
{
    return this->pozycja.x - this->rozmiar.x - przesuniecieZderzenia;
}

double BabyKrowa::wezX2Zderzen()
{
    return this->pozycja.x + this->rozmiar.x + przesuniecieZderzenia;
}

double BabyKrowa::wezY1Zderzen()
{
    return this->pozycja.y - this->rozmiar.y - przesuniecieZderzenia;
}

double BabyKrowa::wezY2Zderzen()
{
    return this->pozycja.y + this->rozmiar.y + przesuniecieZderzenia;
}

XY BabyKrowa::getPozycja()
{
    return pozycja;
}

void BabyKrowa::setPozycja(int x, int y)
{
    this->pozycja.x = x;
    this->pozycja.y = y;
}

void BabyKrowa::setRozmiar(int x, int y)
{
    this->rozmiar.x = x;
    this->rozmiar.y = y;
}

