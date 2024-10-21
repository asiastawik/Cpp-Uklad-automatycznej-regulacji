#include "Regulator.h"

Regulator::Regulator() //konstruktor
{

}

Regulator::~Regulator() //destruktor
{

}

/*"Wprowadzenie agregacji Regulatora z Pomieszczeniem i Grzejnikiem. Dzieki temu to metoda Regulator::steruj (a nie Symulacja::iteracja) bedzie pobierac obecna temperature z
Pomieszczenia, wyznaczyc sygnal sterujący i odpowiednio ustawic moc wyjsciowa Grzejnika."*/

float Regulator::Steruj(float w, float y)
{
	float u = 0;
	return u;
}