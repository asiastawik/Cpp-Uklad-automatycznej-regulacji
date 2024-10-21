#pragma once
#include "Regulator.h"

class RegulatorPID : public Regulator //dziedziczenie
{
	/*"Zaimplementowanie na podobnej zasadzie klasy RegulatorPID, rowniez dziedziczacej po Regulatorze."*/

public:
	float dt; //czas
	float Kp = 1.0, Ki = 0.2, Kd = 0.0; //nastawy -> instrukcja
	float ec = 0, ep = 0;
	float Steruj(float w, float y);
};