#pragma once

class Regulator
{ 
	/*"Zaimplementowanie klasy abstrakcyjnej (moze byc czysto wirtualna) Regulator, ktorej
		metoda steruj przyjmie wartosc zadana temperatury, wartosc zmierzona, a zwroci pozadany
		poziom mocy grzejnika."*/

public:
	Regulator();
	~Regulator();
	virtual float Steruj(float w, float y); //klasa wirtualna
};