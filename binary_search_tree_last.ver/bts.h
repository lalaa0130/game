#pragma once
#include <stdio.h>

class C_BST
{
private:
	struct S_NODE
	{
		int nData;
		S_NODE* pL;
		S_NODE* pR;
	};

private:
	S_NODE* m_pRoot;

private:
	S_NODE** FindNode(S_NODE** ppNode, int nData);
	void FindMaxNode(S_NODE** ppNode, S_NODE*** pppMaxNode);

	S_NODE* createNode(int nData);
	void printNode(S_NODE* pNode);

public:
	C_BST() = default;
	bool Add(int nData);
	bool Erase(int nData);
	bool Find(int nData);
	void Print();
};