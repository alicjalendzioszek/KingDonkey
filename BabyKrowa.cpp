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

