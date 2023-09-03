#pragma once
#include "progression.h"

class C_GEOM_PROGRESSION : public C_PROGRESSON
{
protected:
	// C_PROGRESSON을(를) 통해 상속됨
	virtual float SetToFirstValue() override;
	virtual float SetNextValue() override;

};