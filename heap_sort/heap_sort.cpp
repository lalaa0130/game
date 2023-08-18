#include <iostream>
#include"heap.h"


int main()
{
	C_HEAP cHeap{};

	cHeap.init(9);

	cHeap.addData(4);
	cHeap.addData(7);
	cHeap.addData(6);
	cHeap.addData(3);
	cHeap.addData(8);
	cHeap.addData(1);
	cHeap.addData(2);
	cHeap.addData(5);
	cHeap.addData(9);

	cHeap.printData();

	cHeap.Pop();
	cHeap.printData();

	cHeap.Pop();
	cHeap.printData();
	cHeap.Pop();
	cHeap.printData();
	cHeap.Pop();
	cHeap.printData();

}

