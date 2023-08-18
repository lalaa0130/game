#pragma once
#include<stdio.h>

class C_HEAP
{
private:
	enum {HEAP_NULL = 0};
	
	int *m_pBuffer;
	int m_nBufferLength;
	int m_nDataCount;

private:
	void Swap(int& nDst, int& nSrc);
	int GetChildCount(int nIndex);
	int Compare(int nData1, int nData2);
	
	bool MakeChild(int &nChild,int nParent);

public:
	C_HEAP() = default;
	void init(int nBufferLength);
	void addData(int nData);
	void printData();
	int GetTop();
	void Pop();


};