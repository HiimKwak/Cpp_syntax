#include "Player.h"
#include <iostream>

// 생성자 역할: 기본값 설정, 자원 할당
Player::Player()
{
}

Player::Player(const char* inName)
	//: x(0), y(0), speed(0) : member initialization, 헤더에서 초기화해주는 것과 동일
{
	// x = 0 <- 가능은 하나 성능상 하자가 있음
	// 동적 할당 및 문자열 복사
	size_t length = strlen(inName) + 1;
	name = new char[length];

	// 복사 처리
	strcpy_s(name, length, inName);
}

// 소멸자 역할: 자원 해제
Player::~Player()
{
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
}

// Player:: 범위 지정 연산자(Scope Resolution Operator)
void Player::Move(int inX, int inY)
{
	x = inX;
	y = inY;
}