#include <iostream>
#include "Player.h"

int main()
{
	Player player1;
	player1.Move(5, 2);

	Player* player2 = new Player();
	player2->Move(10, 3); // -> 화살표 연산자 = (*player2).Move(10, 3);와 동일
	delete(player2);
	player2 = nullptr;

	std::cin.get();
}