#include "Grzejnik.h"
#include<iostream>

Grzejnik::Grzejnik() //konstruktor
{

}

Grzejnik::~Grzejnik() //destruktor
{

}

void Grzejnik::ustawGrzejnik(float poziom)
{
	if (poziom < 0)
	{
		procent = 0;
	}

	else if (poziom > 100) //"Zadbaj o zabezpieczenia! Ustawienie poziomu mocy 200% nie powinno być mozliwe."
	{
		procent = 100;
	}

	else
	{
		procent = poziom;
	}
}
