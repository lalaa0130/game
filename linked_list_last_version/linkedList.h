#pragma once

#include"node.h"


class C_LINKED_LIST
{
private:
	C_NODE* m_pBegin;
	C_NODE* m_pEnd;

private:
	C_NODE* createNode(int nData);
	void LinkNode(C_NODE* pPrev, C_NODE* pNext);
	void InsertNode(C_NODE* pPrev, C_NODE* pNode, C_NODE* pNext);


public:
	C_LINKED_LIST();
	~C_LINKED_LIST();
	C_NODE* GetBegin();
	C_NODE* GetEnd();
	C_NODE* GetLastNode();
	void push_back(int nData);
	void push_front(int nData);
	void Erase(C_NODE* pErase);
};