#include "linkedList.h"

C_NODE* C_LINKED_LIST::createNode(int nData)
{
	C_NODE* pNode = new C_NODE{};
	pNode->m_nData = nData;
	pNode->m_pNext = nullptr;
	pNode->m_pPrev = nullptr;

	return pNode;
}

void C_LINKED_LIST::LinkNode(C_NODE* pPrev, C_NODE* pNext)
{
	pPrev->m_pNext = pNext;
	pNext->m_pPrev = pPrev;
}

void C_LINKED_LIST::InsertNode(C_NODE* pPrev, C_NODE* pNode, C_NODE* pNext)
{
	LinkNode(pPrev, pNode);
	LinkNode(pNode, pNext);
}

C_LINKED_LIST::C_LINKED_LIST():
	m_pBegin{},
	m_pEnd{}
{
	m_pBegin = new C_NODE{};
	m_pEnd = new C_NODE{};

	m_pBegin->m_pNext = m_pEnd;
	m_pEnd->m_pPrev = m_pBegin;
}

C_LINKED_LIST::~C_LINKED_LIST()
{
	delete m_pBegin;
	delete m_pEnd;

}

C_NODE* C_LINKED_LIST::GetBegin()
{
	return m_pBegin->m_pNext;
}

C_NODE* C_LINKED_LIST::GetEnd()
{
	return m_pEnd;
}

C_NODE* C_LINKED_LIST::GetLastNode()
{
	return m_pEnd ->m_pPrev;
}

void C_LINKED_LIST::push_back(int nData)
{
	InsertNode(GetLastNode(), createNode(nData), m_pEnd);
}

void C_LINKED_LIST::push_front(int nData)
{
	InsertNode(m_pBegin, createNode(nData), GetBegin());
}

void C_LINKED_LIST::Erase(C_NODE* pErase)
{
	LinkNode(pErase->m_pPrev, pErase->m_pNext);
	delete pErase;
}


