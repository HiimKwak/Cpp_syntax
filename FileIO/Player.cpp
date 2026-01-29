#include <iostream>
#include "Player.h"

Player::Player()
	:Player(0, 0, 0.f) // 아래 생성자 간접호출하도록 연결
{
}
Player::Player(int id, int score, float attack)
	:id(id), score(score), attack(attack)
{
}
Player::~Player() {}

void Player::Serialize(const char* path)
{
	FILE* file = nullptr;
	errno_t error = fopen_s(&file, path, "wt");

	if (!file)
	{
		std::cout << "Failed to open file.\n";
		__debugbreak();
		return;
	}

	/*char outputData[256] = {};
	sprintf_s(outputData, 256, "id=%d score=%d attack=%f", id, score, attack);

	size_t writtenSize = fwrite(outputData, sizeof(char), 256, file);*/

	size_t writtenSize = fprintf_s(
		file,
		"id=%d score=%d attack=%f",
		id, score, attack
	);

	fclose(file);
}

void Player::Deserialize(const char* path)
{
	FILE* file = nullptr;
	errno_t error = fopen_s(&file, path, "rt");
	if (!file)
	{
		std::cout << "Failed to open file.\n";
		__debugbreak();
		return;
	}

	size_t readSize = fscanf_s(file,
		"id=%d score=%d attack=%f",
		&id, &score, &attack
	);

	fclose(file);
}