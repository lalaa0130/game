#include <iostream>
#include "list.h"

int main()
{
	C_BTS cBts{};
	
	cBts.Insert(44);
	cBts.Insert(32);
	cBts.Insert(56);
	cBts.Insert(28);
	cBts.Insert(35);
	cBts.Insert(33);
	cBts.Insert(37);
	

	cBts.print();
	cBts.Erase(32);
	cBts.print();
}

