#pragma once
#include"progression.h"

class C_NEW_PROGRSSION : public C_PROGRESSON
{
public:
	virtual float SetToFirstValue();
	virtual void Init(float fFirst, float fSecond) override;
	virtual void printProgession(int nData);

	virtual float SetNextValue() override;

};