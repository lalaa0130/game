#pragma once
#include "progression.h"

class C_GEOM_PROGRESSION : public C_PROGRESSON
{
protected:
	// C_PROGRESSON��(��) ���� ��ӵ�
	virtual float SetToFirstValue() override;
	virtual float SetNextValue() override;

};