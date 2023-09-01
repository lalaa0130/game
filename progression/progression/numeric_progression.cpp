#include <iostream>
#include"arithProgression.h"
#include "geomProgression.h"

int main()
{
	C_PROGRESSON* cNumericProgression{};
	cNumericProgression = new C_ARITH_PROGRESSION{};

	
	cNumericProgression->Init(5, 5);
	cNumericProgression->printProgession(5);
	
	cNumericProgression = new C_GEOM_PROGRESSION{};
	cNumericProgression->Init(3.f, 3.f);
	cNumericProgression->printProgession(10);
}


