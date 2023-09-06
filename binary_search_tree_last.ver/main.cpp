#include <iostream>
#include "bts.h"

int main()
{
	C_BST cBst{};

	cBst.Add(8);
	cBst.Add(5);
	cBst.Add(6);
	cBst.Add(2);
	cBst.Add(9);
	cBst.Add(7);
	cBst.Add(4);
	cBst.Add(1);
	cBst.Add(3);

	cBst.Print();
	cBst.Erase(3);
	cBst.Print();

	if (cBst.Find(100))
		printf("Find!\n");
	else
		printf("No data\n");
}

