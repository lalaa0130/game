#pragma once
#include "progression.h"

class C_ARITH_PROGRESSION : public C_PROGRESSON
{
protected:
	virtual float SetNextValue() override;

public:
	C_ARITH_PROGRESSION() = default;
	virtual void printProgession(int nData) override;



};