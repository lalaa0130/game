#pragma once
#include <stdio.h>

class C_BTS
{
private :
	struct S_NODE
	{
		int nData;
		S_NODE* pL;
		S_NODE* pR;
	};

private:
	S_NODE* m_pRootNode;

private:
	S_NODE* createNode(int nData);
	S_NODE* createInsertNode(S_NODE** pNode,int nData,bool *ifInsert);
	void TreeSearch(S_NODE* pNode, int nData,S_NODE& pFindNode);

	void printNode(S_NODE* pNode);
public:
	C_BTS() = default;
	~C_BTS() = default;
	bool Insert(int nData);
	void Erase(int nData);
	void print();
	void FindNode(S_NODE* pStartNode,S_NODE & pMinNode);
};