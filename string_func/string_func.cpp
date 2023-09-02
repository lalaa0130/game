#include<stdio.h>
#include<iostream>
#include <queue>

void CountVowel(const char* pString, int* nCount);
void deletePunctuation(const char* pString, const int pStrLength, char* pStr);
void GetPunctuationList(const char* pString, std::queue<int>& qList);

int main()
{
	int nCount{};
	CountVowel("It's a good day!\n", &nCount);
	printf("%d\n", nCount);

	const char* pStr{ "I, Love !g@o# t**o )S$!e>a?" };

	char* newStr{};
	deletePunctuation(pStr, 28, newStr);
}

void CountVowel(const char* pString, int* nCount)
{
	char arVowel[5]{ 'a','e','i','o','u' };

	const char* pTempString = pString;

	*nCount = 0;
	for (int i = 0; i < 5; i++)
	{
		pTempString = pString;
		while (*pTempString != '\0')
		{
			if (*pTempString == arVowel[i] || *pTempString == (char)(arVowel[i] - 32))
			{
				(*nCount)++;
			}
			pTempString++;
		}
	}


}

void deletePunctuation(const char* pString, const int pStrLength, char* pStr)
{
	std::queue<int> qList{};
	GetPunctuationList(pString, qList);
	int nDstStrLength = pStrLength - qList.size() + 1;
	pStr = new char[nDstStrLength] {};

	const char* pTempStr = pString;

	int deleteIndex = qList.front();
	qList.pop();

	int nDstIndex{};
	int nSrcIndex{};
	while (pTempStr[nSrcIndex] != '\0')
	{
		if (nSrcIndex == deleteIndex)
		{
			if (!qList.empty())
			{
				deleteIndex = qList.front();
				qList.pop();
			}
		}
		else
		{
			pStr[nDstIndex] = pTempStr[nSrcIndex];
			nDstIndex++;
		}
		nSrcIndex++;
	}
	pStr[nDstIndex] = '\0';

	printf("%s\n", pStr);
}

void GetPunctuationList(const char* pString, std::queue<int>& qList)
{
	const char* pTempStr = pString;
	while (*pTempStr != '\0')
	{
		if (*pTempStr != 32)
		{
			if (*pTempStr < 'A' ||
				(*pTempStr > 'Z' && *pTempStr < 'a') ||
				*pTempStr > 'z')
			{
				qList.push(pTempStr - pString);
			}
		}
		pTempStr++;
	}

}

