#pragma once
#include<stdio.h>

class C_PROGRESSON
{
protected:
	float f_fFirst;
	float f_fCurrent;
	float f_fAddNum;

protected:
	virtual float SetNextValue() = 0;
	virtual float SetToFirstValue();
	
public:
	virtual void Init(float fFirst,float fAdd);
	void printProgession(int nData);
	
public:
	C_PROGRESSON() = default;
	virtual ~C_PROGRESSON() {};	
	/*C_PROGRESSON(const C_PROGRESSON&) = delete;
	C_PROGRESSON& operator = (const C_PROGRESSON&) = delete;*/



};