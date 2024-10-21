#include "RegulatorPID.h"
#include <iostream>

float RegulatorPID::Steruj(float w, float y)
{
	float e = w - y; //wzory z instrukcji
	float up = Kp * e;
	ec += e * dt;
	//std::cout << ec; 
	float ui = Ki * ec;

	if (dt <= 0) //zabezpieczenie przed dzieleniem przez zero
	{
		throw "Nie minal czas.\n";
	}

	float de = (e - ep) / dt;
	ep = e;
	float ud = Kd * de;

	float u = up + ui + ud;
	//std::cout << "\n" << u;

	return u;
}
