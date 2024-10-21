#include "Symulacja.h"
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "RegulatorBB.h"
#include <iostream>
#include <Windows.h> 
#include <fstream>
#include <locale.h>

struct ustawieniePrzecinka : std::numpunct<char> 
{
	char do_decimal_point() const override { return ','; }
};

Symulacja::Symulacja(int szer, int dl, int gleb) //konstruktor
{
	pokoj = new Pomieszczenie(szer, dl, gleb);
	grzejnik = new Grzejnik;
	regulatorBB = new RegulatorBB;
	regulatorPID = new RegulatorPID;
}

Symulacja::~Symulacja() //destruktor
{
	temperatura.clear(); //czyscimy tez wektory
	czas.clear();
	moc.clear();
	delete pokoj;
	delete grzejnik;
	delete regulatorBB;
	delete regulatorPID;
}

void Symulacja::iteracja(float dt)
{
	/*"Metoda iteracja ma wykonywac pojedynczy krok symulacji, przyjmujac liczbc zmiennoprzecinkowa okreslajaca czas uplywajacy w tym kroku (Δ𝑡)."*/

	system("cls");
	pokoj->dodajCieplo(grzejnik->getAktualnaMoc());
	pokoj->aktualizuj(dt);
	std::cout << "Aktualna temperatura: " << pokoj->getTemperatura() << std::endl << "Aktulna moc grzejnika: " << grzejnik->getAktualnaMoc() << "W" << std::endl;
}

void Symulacja::przebieg(int n, float dt, char regulator)
{
	/*"Metoda przebieg ma pozwalac na wykonanie okreslonej liczby iteracji o podanym czasie probkowania."*/

	float t = 0;

	if (regulator == 'b')
	{
		for (int i = 0; i < n; i++)
		{
			grzejnik->ustawGrzejnik(regulatorBB->Steruj(getZadana(), pokoj->getTemperatura())); //wywolujemy metode steruj
			iteracja(dt); //"W kazdym kroku aktualizuj stan Pomieszczenia i wydrukuj jego aktualna temperatura na konsoli."
			temperatura.push_back(pokoj->getTemperatura());
			moc.push_back(grzejnik->getAktualnaMoc()); //push_back dodaje nowy element na koniec wektora
			czas.push_back(t);
			t += dt; //zmieniamy czas
		}
	}

	else if (regulator == 'p')
	{
		for (int i = 0; i < n; i++)
		{
			regulatorPID->dt = dt;
			grzejnik->ustawGrzejnik(regulatorPID->Steruj(getZadana(), pokoj->getTemperatura())); //wywolujemy metode steruj
			iteracja(dt);
			temperatura.push_back(pokoj->getTemperatura());
			moc.push_back(grzejnik->getAktualnaMoc());
			czas.push_back(t);
			t += dt;
		}
	}

	else
	{
		throw "Nieprawidlowy regulator!\n";
	}
}

void Symulacja::zapis()
{
	/*"Rozszerz klase Symulacja o automatyczne zapisywanie przebiegow: temperatury, aktualnego
		czasu, oraz aktualnej mocy wyjsciowej grzejnika uzywajac szablonu std::vector. Dopisz do
		niej metode zapis, umozliwiajaca eksport tych danych do pliku CSV."*/

	int dlugosc = temperatura.size();

	if (dlugosc > 0)
	{
		std::ofstream plik;
		plik.open("wynik.csv", std::ifstream::out); //otwieranie plikow 
		//std::locale pol("pl_PL"); //przecinki zamiast kropek
		//std::locale pol(""); //przecinki zamiast kropek
		//plik.imbue(pol);
		
		std::locale wlasne(plik.getloc(), new ustawieniePrzecinka);
		plik.imbue(wlasne);
	
		if (plik.good())
		{
			plik << "Temperatura" << ";" << "Moc" << ";" << "Czas" << std::endl;
			for (int i = 0; i < dlugosc; i++)
			{
				plik << temperatura[i] << ";" << moc[i] << ";" << czas[i] << std::endl;
			}
			std::cout << "Wyniki poprawnie zapisano do pliku wynik.csv.\n";
		}

		else
		{
			std::cout << "Niestety, nie udalo sie otworzyc pliku.\n" << std::endl;
		}
		plik.close();
	}

	else
	{
		throw "\nBrak danych do zapisania.\n";
	}
}

void Symulacja::UstawZadana()
{
	std::cout << "Podaj zadana temperature: ";
	char c[10];
	int i;
	do //zabezpieczenie przed wprowadzaniem liter/zlych wartosci
	{
		std::cin >> c;

		int m = strlen(c);
		for (i = 0; i < m; i++)
		{
			if (c[i] >= 48 && c[i] <= 57 || c[i] == 44 || c[i] == 46) //przedzial od 0 do 9 lub , lub .
			{
				zadana = atof(c);
			}
			else
			{
				zadana = -1;
				std::cout << "Niepoprawna wartosc. Prosze podac dodatnia liczbe zmiennoprzecinkowa.\n" << std::endl;
			}
		}
	} while (zadana < 0);
}