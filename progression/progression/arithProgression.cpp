#include "arithProgression.h"

void C_ARITH_PROGRESSION::printProgession(int nData)
{
	C_PROGRESSON::printProgession(nData);
}


float C_ARITH_PROGRESSION::SetNextValue()
{
	f_fCurrent += f_fAddNum;
	return f_fCurrent;
}
