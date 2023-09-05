// binary_research.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

const int* binarySearch(const int* pData, int nLength, int nFindData);
const int* binarySearchR(const int* pData, int nLength, int nFindData);


int main()
{
	int arData[50]{};

	for (int i = 0; i < 50; i++)
	{
		arData[i] = i * 5;
	}


	int nFindData{};
	scanf_s("%d",&nFindData);

	const int* pData{};

	if (pData = binarySearchR(arData, 50, nFindData))
		printf("Find %d\n", (int)(pData - arData));
	else
		printf("no data\n");


}

const int* binarySearch(const int* pData, int nLength, int nFindData)
{
	bool ifFind = false;
	int nFindIndex = nLength / 2;
	while (ifFind || nLength > 1)
	{
		if (pData[nFindIndex] < nFindData)
		{
			nLength -= (nFindIndex + 1);
			pData += (nFindIndex + 1);
			nFindIndex = nLength / 2;
		}
		else if (pData[nFindIndex] > nFindData)
		{
			nLength = nFindIndex;
			nFindIndex = nLength / 2;
		}
		else if (pData[nFindIndex] == nFindData)
		{
			ifFind = true;
		}
	}

	if (!ifFind) 
		return nullptr;
	
	return pData + nFindIndex;
}

const int* binarySearchR(const int* pData, int nLength, int nFindData)
{

	if (nLength <= 0)
		return nullptr;

	int nFindIndex = nLength / 2;
	if (pData[nFindIndex] < nFindData)
	{
		nLength -= (nFindIndex + 1);
		pData += (nFindIndex + 1);
		return binarySearchR(pData,nLength,nFindData);
	}
	else if (pData[nFindIndex] > nFindData)
	{
		nLength = nFindIndex;
		return binarySearchR(pData, nLength, nFindData);
	}


	return pData + nFindIndex;

}
