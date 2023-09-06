// binary_search_tree_lastversion.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include"bst.h"

int main()
{
	C_BST bst{};

	bst.Add(5);
	bst.Add(6);
	bst.Add(7);
	bst.Add(9);
	bst.Add(10);

	bst.print();



}
