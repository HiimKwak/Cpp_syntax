#include <iostream>
#include "Player.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Player player1;
	player1.Move(5, 2);

	// heap
	Player* player2 = new Player("Miles");
	player2->Move(10, 3); // -> 화살표 연산자 = (*player2).Move(10, 3);와 동일
	delete(player2);
	player2 = nullptr;

	std::cin.get();
}