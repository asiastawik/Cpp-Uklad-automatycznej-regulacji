#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include <vector>

class Symulacja
{
public:
	Symulacja(int szer, int dl, int gleb);
	~Symulacja();

	void iteracja(float dt);
	void przebieg(int n, float dt, char regulator);

	/*"Uwzglednij w Symulacji mozliwosc posiadania w sposob polimorficzny instancji Regulatora
		wraz z odpowiednimi metodami do jej ustawienia, oraz kodem do obslugi jego dzialania w
		trakcie poszczegolnych iteracji symulacji."*/

	Pomieszczenie* pokoj;
	Grzejnik* grzejnik;
	RegulatorBB* regulatorBB;
	RegulatorPID* regulatorPID;

	float zadana;  // temperatura zadana
	void UstawZadana();
	float getZadana() { return zadana; }

	/*Rozszerz klase Symulacja o automatyczne zapisywanie przebiegow: temperatury, aktualnego 
		czasu, oraz aktualnej mocy wyjsciowej grzejnika uzywajac szablonu std::vector"*/

	std::vector <float> temperatura;
	std::vector <float> czas;
	std::vector <float> moc;

	void zapis();
};