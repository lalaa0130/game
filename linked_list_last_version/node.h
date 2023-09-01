#pragma once

class C_LINKED_LIST;

class C_NODE
{
	friend C_LINKED_LIST;

private:
	int m_nData;

	C_NODE* m_pPrev;
	C_NODE* m_pNext;

private :
	C_NODE() = default;
	C_NODE(const C_NODE&) = default;
	C_NODE& operator = (const C_NODE&) = delete;

public:
	int GetData();
	C_NODE* GetNext();
	


};