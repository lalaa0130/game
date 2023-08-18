#include "heap.h"
#include<assert.h>

void C_HEAP::Swap(int& nDst, int& nSrc)
{
	int nTmp = nSrc;
	nSrc = nDst;
	nDst = nTmp;
}

int C_HEAP::GetChildCount(int nIndex)
{
	int nLeftChild = nIndex * 2;
	int nRightChild = nIndex * 2 + 1;
	if (nRightChild <= m_nDataCount)
		return 2;
	if (nLeftChild <= m_nDataCount)
		return 1;

	return 0;
}

int C_HEAP::Compare(int nData1, int nData2)
{
	if (m_pBuffer[nData1] > m_pBuffer[nData2])
		return nData1;
	return nData2;
}

bool C_HEAP::MakeChild(int& nChild, int nParent)
{
	nChild = nParent * 2;
	if (nChild + 1 <= m_nDataCount && m_pBuffer[nChild] < m_pBuffer[nChild + 1])
	{
		nChild++;
	}

	if (nChild > m_nDataCount)
		return false;

	return true;
}

void C_HEAP::init(int nBufferLength)
{
	if (!m_pBuffer)
	{
		m_nDataCount = 0;
		m_nBufferLength = nBufferLength + 1;
		//m_pBuffer[0] = C_HEAP::HEAP_NULL;
		m_pBuffer = new int[m_nBufferLength] {};
	}

}

void C_HEAP::addData(int nData)
{
	if (m_nBufferLength > m_nDataCount)
	{
		m_nDataCount++;
		m_pBuffer[m_nDataCount] = nData;
	
		int nCurrent = m_nDataCount;
		int nUp = nCurrent / 2;

		while (nUp != C_HEAP::HEAP_NULL && m_pBuffer[nCurrent] > m_pBuffer[nUp])
		{
			int nTmp = m_pBuffer[nUp];
			m_pBuffer[nUp] = m_pBuffer[nCurrent];
			m_pBuffer[nCurrent] = nTmp;
			
			nCurrent = nUp;
			nUp /= 2;
		}
	
	
	}


}

void C_HEAP::printData()
{
	for (int i = 1; i <= m_nDataCount; i++)
	{
		printf("%d ", m_pBuffer[i]);
	}
	printf("\n");
}

int C_HEAP::GetTop()
{
	assert(m_nDataCount > 0 && "buffer is empty!\n");
	return m_pBuffer[1];
}

void C_HEAP::Pop()
{
	assert(m_nDataCount > 0 && "buffer is empty!\n");
	m_pBuffer[1] = m_pBuffer[m_nDataCount];
	m_nDataCount--;


	int nCurrentIndex = 1;
	int nChildIndex{};
	
	while (MakeChild(nChildIndex, nCurrentIndex) && m_pBuffer[nCurrentIndex] < m_pBuffer[nChildIndex])
	{
		Swap(m_pBuffer[nCurrentIndex], m_pBuffer[nChildIndex]);
		nCurrentIndex = nChildIndex;
	}

	int nChildrenCount = GetChildCount(nCurrentIndex);
	int nLeftIndex{};
	int nRightIndex{};
	int nBiggerIndex{};

	while (nChildrenCount >= 1)
	{
		nLeftIndex = nCurrentIndex * 2;
		nRightIndex = nCurrentIndex * 2 + 1;
		nBiggerIndex = nLeftIndex;

		if(nChildrenCount == 2 && m_pBuffer[nLeftIndex] < m_pBuffer[nRightIndex])
		{
			nBiggerIndex = nRightIndex;
		}

		if (m_pBuffer[nCurrentIndex] < m_pBuffer[nBiggerIndex])
		{
			Swap(m_pBuffer[nCurrentIndex], m_pBuffer[nBiggerIndex]);
			nCurrentIndex = nBiggerIndex;
		}
		else
		{
			nCurrentIndex = m_nDataCount;
		}
		nChildrenCount = GetChildCount(nCurrentIndex);


	}

}
