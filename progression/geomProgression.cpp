#include "geomProgression.h"

float C_GEOM_PROGRESSION::SetToFirstValue()
{
    return C_PROGRESSON::SetToFirstValue();
}

float C_GEOM_PROGRESSION::SetNextValue()
{
    f_fCurrent *= f_fAddNum;
    return f_fCurrent;
}


