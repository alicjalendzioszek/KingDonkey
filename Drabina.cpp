#include "Drabina.h"

double Drabina::wezX1Zderzen()
{
	return this->pozycja.x - this->rozmiar.x + 3*przesuniecieZderzenia;
}

double Drabina::wezX2Zderzen()
{
	return this->pozycja.x + this->rozmiar.x - 3*przesuniecieZderzenia;
}

double Drabina::wezY1Zderzen()
{
	return this->pozycja.y - this->rozmiar.y - przesuniecieZderzenia;
}

double Drabina::wezY2Zderzen()
{
	return this->pozycja.y + this->rozmiar.y + przesuniecieZderzenia;
}