#include <iostream>
#include"arithProgression.h"
#include "geomProgression.h"
#include "newPregression.h"

int main()
{
	C_PROGRESSON* cNumericProgression{};

	cNumericProgression = new C_ARITH_PROGRESSION{};
	cNumericProgression->Init(1, 128);
	cNumericProgression->printProgession(10);
	
	cNumericProgression = new C_GEOM_PROGRESSION{};
	cNumericProgression->Init(3.f, 3.f);
	cNumericProgression->printProgession(10);

	cNumericProgression = new C_NEW_PROGRSSION{};
	cNumericProgression->Init(2.f, 200.f);
	cNumericProgression->printProgession(10);

}


