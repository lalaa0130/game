#include <Windows.h>
#include "game.h"
#include <stdio.h>

void C_GAME::swap(int& nDst, int& nSrc)
{
	int nTmp = nDst;
	nDst = nSrc;
	nSrc = nTmp;

}

int C_GAME::random(int nMin, int nMax)
{
	return (int)(((double)rand() / (RAND_MAX + 1)) * (nMax- nMin) + nMin);
}


void C_GAME::init()
{
	srand(timeGetTime());
	int arData[10] = { 0,1,2,3,4,5,6,7,8,9 };
	S_NODE arNode[5]{};

	for (int i = 0; i < 20; i++)
	{
		swap(arData[random(0, 10)], arData[random(0, 10)]);
	}

	for (int i = 0; i < 4; i++)
	{
		arNode[i].pNext = &arNode[i + 1];
		arNode[i].pNum = &arData[i];
	}
	arNode[3].pNext = &arNode[0];
	S_NODE* pNode = &arNode[0];

	int arTable[4]{};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arTable[i] = *pNode->pNum;
			pNode = pNode->pNext;
		}
		m_arTable[i].init(arTable[0], arTable[1], arTable[2], arTable[3]);
		pNode = pNode->pNext;
	}

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arData[i]);
	}


}

bool C_GAME::input(int* pNumber, int nLength)
{
	bool arInputTable[10]{};
	bool bResult = true;

	for (int i = 0; i < 4; i++)
	{
		scanf_s("%d", &pNumber[i]);
		if (arInputTable[pNumber[i]])
			bResult = false;
		arInputTable[pNumber[i]] = true;
	}

	return bResult;
}

void C_GAME::run()
{
	int arInputNumber[4]{};


	int arResult[C_TABLE::E_RESULT::E_MAX]{};

	while (arResult[C_TABLE::E_STRIKE] != 4)
	{
		arResult[C_TABLE::E_STRIKE] = 0;
		arResult[C_TABLE::E_BALL] = 0;
		while (!input(arInputNumber, 4))
		{
			printf("다시입력하세요\n");
		}

		for (int i = 0; i < 4; i++)
		{
			arResult[m_arTable[i].getResult(arInputNumber[i])]++;
		}

		printf("Strike: %d , Ball: %d\n", arResult[C_TABLE::E_STRIKE], arResult[C_TABLE::E_BALL]);

	}

}