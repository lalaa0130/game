#include "newPregression.h"

float C_NEW_PROGRSSION::SetToFirstValue()
{
    f_fCurrent = f_fFirst;

    return f_fCurrent;
}
void C_NEW_PROGRSSION::Init(float fFirst, float fSecond)
{
    f_fFirst = fFirst;
    f_fAddNum = -(fSecond + f_fFirst);
}

void C_NEW_PROGRSSION::printProgession(int nData)
{
    C_PROGRESSON::printProgession(nData);
}

float C_NEW_PROGRSSION::SetNextValue()
{
    float fNext = f_fCurrent + f_fAddNum;
    if (fNext < 0)
        fNext *= -1;
    f_fAddNum = -f_fCurrent;
    f_fCurrent = fNext;

    return fNext;

}
