#include "list.h"

bool C_BTS::Insert(int nData)
{
	if (!m_pRootNode)
	{
		m_pRootNode = createNode(nData);
		return true;
	}

	S_NODE* pNode = m_pRootNode;
	bool ifInsert = false;
	while (!ifInsert)
	{
		if (pNode->nData < nData)
		{
			pNode = createInsertNode(&(pNode->pR), nData,&ifInsert);
		}
		else if (pNode->nData > nData)
		{
			pNode = createInsertNode(&(pNode->pL), nData ,&ifInsert);
		}
	}

	return true;
}

void C_BTS::Erase(int nData)
{
	S_NODE* pNode = m_pRootNode;
	S_NODE* pUp = nullptr;

	while (pNode && pNode->nData != nData)
	{
		pUp = pNode;
		if (pNode->nData > nData)
		{
			pNode = pNode->pL;
		}
		else if (pNode->nData < nData)
			pNode = pNode->pR;
	}
	if (!pNode)
		return;
	printf("find erase number %d\n", pNode->nData);

	if (pNode->pL && pNode->pR)
	{
		// 경우pNode노드의 오른쪽 하위 트리에서 가장 작은 노드를 찾습니다. 
		//삭제할 노드의 값을pMin의 값으로 바꾸고이 노드에서 삭제를 재귀 적으로 호출합니다.
		S_NODE* pTmp = pNode->pR;
		S_NODE pMinNode = *pTmp;
		FindNode(pTmp, pMinNode);
		//printf("minNode in Right: %d\n", pMinNode->nData);
		
		printf("minNode:%d\n", pMinNode.nData);
		if (pUp->pL == pNode)
			pUp->pL = &pMinNode;
		else
			pUp->pR = &pMinNode;

		pMinNode.pL = pNode->pL;
		pMinNode.pR = pNode->pR;

		delete pNode;
	}
	else
	{
		S_NODE* pTmp = pNode->pL;
		if (pNode->pR)
			pTmp = pNode->pR;
		
		if (pUp->pL == pNode)
			pUp->pL = pTmp;
		else
			pUp->pR = pTmp;

		delete pNode;
	}

}

C_BTS::S_NODE* C_BTS::createNode(int nData)
{
	S_NODE* pNode = new S_NODE{};

	pNode->nData = nData;
	pNode->pL = nullptr;
	pNode->pR = nullptr;

	return pNode;
}

C_BTS::S_NODE* C_BTS::createInsertNode(S_NODE** pInsertNode, int nData, bool* ifInsert)
{

	if (!(*pInsertNode))
	{
		*pInsertNode = createNode(nData);
		*ifInsert = true;
	}
	return *pInsertNode;
}

void C_BTS::TreeSearch(S_NODE* pNode,int nData,S_NODE& pFindNode)
{
	if(pNode->nData == nData)
	{
		pFindNode = *pNode;
		printf("pFindNode : %d\n", pFindNode.nData);
		return;
	}
	int nCurrData = pNode->nData;
	
	if (nCurrData > nData)
	{	
		TreeSearch(pNode->pL, nData,pFindNode);
	}
	else if(nCurrData < nData)
	{
		TreeSearch(pNode->pR, nData,pFindNode);
	}
}

void C_BTS::printNode(S_NODE* pNode)
{
	if (!pNode)
		return;

	printf("%d ", pNode->nData);
	printNode(pNode->pL);
	printNode(pNode->pR);
}


void C_BTS::print()
{
	printNode(m_pRootNode);
	printf("\n");
}

void C_BTS::FindNode(S_NODE * pStratNode ,S_NODE&pMinNode)
{
	//S_NODE& pNode = *m_pRootNode;

	////왜 나오면 pNode 는 nullptr로 되어있는지
	//TreeSearch(m_pRootNode, nData ,pNode);
	//	printf("Finf %d node\n", pNode.nData);
	//return false;
	if (!pStratNode)
		return;
	
	printf("findNode %d\n", pStratNode->nData);
	printf("minNode %d\n", pMinNode.nData);
	if (pMinNode.nData > pStratNode->nData)
	{
		printf("change\n");
		pMinNode = *pStratNode;
	}

	FindNode(pStratNode->pL,pMinNode);
	FindNode(pStratNode->pR,pMinNode);

}
