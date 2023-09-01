#pragma once
#include<stdio.h>

class C_PROGRESSON
{
protected:
	float f_fFirst;
	float f_fCurrent;
	float f_fAddNum;
protected:
	// C_PROGRESSION_INTERFACE을(를) 통해 상속됨
	virtual float SetToFirstValue();
	virtual float SetNextValue();
	

public:
	void Init(float fFirst,float fAdd);
	virtual void printProgession(int nData);
	

public:
	C_PROGRESSON() = default;
	virtual ~C_PROGRESSON() {};	
	/*C_PROGRESSON(const C_PROGRESSON&) = delete;
	C_PROGRESSON& operator = (const C_PROGRESSON&) = delete;*/



};