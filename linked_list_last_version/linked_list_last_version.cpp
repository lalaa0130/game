// linked_list_last_version.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "linkedList.h"

int main()
{
	C_LINKED_LIST cLinkedList{};

	cLinkedList.push_back(1);
	cLinkedList.push_back(2);
	cLinkedList.push_back(3);
	cLinkedList.push_back(4);
	cLinkedList.push_front(4);
	cLinkedList.push_front(3);
	cLinkedList.push_front(2);
	cLinkedList.push_front(1);

	C_NODE* pNode = cLinkedList.GetBegin();
	while (pNode != cLinkedList.GetEnd())
	{
		C_NODE* pNext = pNode->GetNext();

		if (pNode->GetData() == 4)
			cLinkedList.Erase(pNode);
		pNode = pNext;
	}

	pNode = cLinkedList.GetBegin();
	while (pNode != cLinkedList.GetEnd())
	{
		C_NODE* pNext = pNode->GetNext();

		printf("%d ", pNode->GetData());

		pNode = pNext;
	}

}

