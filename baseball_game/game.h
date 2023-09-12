#pragma once
#include"table.h"

class C_GAME
{
private:
	struct S_NODE
	{
		int* pNum;
		S_NODE* pNext;
	};

private:
	C_TABLE m_arTable[4];

private:
	void swap(int &nDst,int &nSrc);
	int random(int nMin, int nMax);
	bool input(int* pNumber, int nLength);

public:
	C_GAME() = default;
	void init();
	void run();

};
