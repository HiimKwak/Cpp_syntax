#include <iostream>
#include <memory>

class Player
{
public:
	Player()
	{
		std::cout << "생성자 호출\n";
	}
	~Player()
	{
		std::cout << "소멸자 호출\n";
	}
	// 명시적으로 복사 생성자, 대입 연산자를 delete로 지워버리거나
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;
	//private: // 복사 생성자, 대입 연산자를 private으로 숨겨버리거나
	//	Player(const Player& other) {}
	//	Player& operator=(const Player& other) { return *this; }

};

// 1. 포인터의 참조를 전달하면 내부에서 사용가능
//void Function(std::unique_ptr<Player>& player)
//{
//	//Player* rawPointer = player.get(); // 스마트포인터.get()으로 포인터를 받아올 수 있다
//	//delete rawPointer; // 가능하나 위험함
//}

// 2. 원시 포인터
void Function(Player* player)
{
	//delete player; // 가능하나 위험함
}

// 3. 레퍼런스 전달
void Function(Player& player)
{
	//delete player; // 참조이기 때문에 삭제 불가능
}

int main()
{
	std::unique_ptr<Player> player = std::make_unique<Player>();

	Function(*player);
	//Function(std::make_unique<Player>()); // 함수 초기화와 동시에 매개변수에 소유권 부여하는 경우는 가능하나 잘 안쓰인다

	//std::unique_ptr<Player> player2 = player; // 복사 생성자, 대입 연산자를 아예 지워버림
	/*std::unique_ptr<Player> player2;
	player2 = std::move(player);*/

	std::cin.get();
}