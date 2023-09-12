
#include <iostream>
#include <Windows.h>
#include "game.h"

int main()
{
	C_GAME cGame{};

	cGame.init();
	cGame.run();


}

