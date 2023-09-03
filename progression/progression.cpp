#include "progression.h"

float C_PROGRESSON::SetToFirstValue()
{
	f_fCurrent = f_fFirst;
	return f_fCurrent;
}

float C_PROGRESSON::SetNextValue()
{
	f_fCurrent++;
	return f_fCurrent;
}

void C_PROGRESSON::Init(float fFirst, float fAdd)
{
	f_fFirst = fFirst;
	f_fCurrent = f_fFirst;
	f_fAddNum = fAdd;
}

void C_PROGRESSON::printProgession(int nData)
{
	printf("%.2f ", SetToFirstValue());
	for (int i = 2; i < nData; i++)
	{
		printf("%.2f ", SetNextValue());
	}
	printf("\n");
}

