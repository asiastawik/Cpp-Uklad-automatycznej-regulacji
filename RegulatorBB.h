#pragma once
#include "Regulator.h"

class RegulatorBB : public Regulator //dziedziczenie po Regulatorze
{
	/*"Zaimplementowanie klasy RegulatorBB (od „bang-bang”) dziedziczacej po Regulatorze. Ma
		ona być wyposazona w implementacje metody steruj wykonująca opisany powyzej algorytm
		sterowania dwupolozeniowego. "*/

public:
	float Steruj(float zadana, float aktulana);
};