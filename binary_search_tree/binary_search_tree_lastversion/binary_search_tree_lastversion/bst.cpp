#include "bst.h"


C_BST::S_NODE** C_BST::findNode(S_NODE** ppNode,int nData)
{
	if (!*ppNode)
		return ppNode;

	if ((*ppNode)->nData > nData)
		return findNode(&(*ppNode)->pL, nData);
	else if ((*ppNode)->nData < nData)
		return findNode(&(*ppNode)->pR, nData);
	
	return ppNode;
}

C_BST::S_NODE* C_BST::createNode(int nData)
{
	S_NODE* pNode = new S_NODE{};
	
	pNode->nData = nData;
	pNode->pL = nullptr;
	pNode->pR = nullptr;

	return pNode;
}

void C_BST::PrintNode(S_NODE* pNode)
{
	if (!pNode)
		return;

	printf("%d ", pNode->nData);
	PrintNode(pNode->pL);
	PrintNode(pNode->pR);
}

C_BST::S_NODE** C_BST::findMaxNode(S_NODE** ppNode)
{
	if (!((*ppNode)->pR))
		return ppNode;

	return nullptr;
}

bool C_BST::Add(int nData)
{
	S_NODE** ppFind = findNode(&m_pRoot, nData);

	if (*ppFind)
		return false;

	*ppFind = createNode(nData);

	//있으면 실패
	//없으면 찾은자리에 추가
	return true;
}

bool C_BST::Erase(int nData)
{
	S_NODE** ppFind = findNode(&m_pRoot, nData);

	if (!*ppFind)
		return false;

	if ((*ppFind)->pL && (*ppFind)->pR)
	{
		S_NODE** ppMax = findMaxNode(&(*ppFind)->pL);
		(*ppFind)->nData = (*ppMax)->nData;
		ppFind = ppMax;
	}

	S_NODE* pDel = *ppFind;
	*ppFind = pDel->pL;
	if (pDel->pL)
		*ppFind = pDel->pR;

	delete pDel;
	return true;
}

void C_BST::print()
{
	PrintNode(m_pRoot);
}
