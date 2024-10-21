#include "RegulatorBB.h"

float RegulatorBB::Steruj(float w, float y)
{ 
	//sterowanie dwupoziomowe

	if (y < w)
	{
		return 100.0;
	}

	else
	{
		return 0;
	}
}
