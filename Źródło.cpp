#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include "Pomieszczenie.h"
#include "Symulacja.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"


void ustawWymiary(float* wys, float* szer, float* gleb)
{
	float temp;
	std::cout << "Podaj wysokosc: ";
	std::cin >> temp;
	*wys = temp;
	std::cout << "\nPodaj szerokosc: ";
	std::cin >> temp;
	*szer = temp;
	std::cout << "\nPodaj glebokosc: ";
	std::cin >> temp;
	*gleb = temp;
}

int main()
{
	setlocale(LC_ALL, ".1250"); //polskie znaki
	float wys, szer, gleb;
	char reg; //wybor regulatora
	//ustawWymiary(&wys, &szer, &gleb); //jesli chcielbysmy zeby uzytkownik podal wymiary
	wys = 2.5;
	szer = 4;
	gleb = 4;
	Pomieszczenie* pokoj = new Pomieszczenie(wys, szer, gleb);
	Symulacja* symulator = new Symulacja(wys, szer, gleb);
	Grzejnik* grzejnik = new Grzejnik;
	symulator->grzejnik = grzejnik;
	symulator->UstawZadana();

	do
	{
		std::cout << "Jakiego regulatora chcesz uzywac? " << std::endl << "b - Regulator Bang-Bang" << std::endl << "p - Regulator PID" << std::endl;
		std::cin >> reg;
		if (reg != 'b' && reg != 'p') //zabezpieczenie
		{
			std::cout << "Oczekiwano b lub p!\n";
		}
	} while (reg != 'b' && reg != 'p');

	int x;

	if (reg == 'b')
	{
		x = 1;
	}

	if (reg == 'p')
	{
		x = 60;
	}

	try
	{
		symulator->przebieg(100, x, reg); //100 to liczba symulacji, x to czas probkowania
		symulator->zapis();
	}

	catch (const char* e) //char, bo "b" i "p" to znaki
	{
		std::cout << "Blad!" << e << std::endl;
	}

	return 0;
}