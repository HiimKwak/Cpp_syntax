#pragma once // 중복 include 방지 전처리 구문

class Player
{
	// 접근 한정/제한자: 내부 속성을 어디까지 노출시킬지 결정
	// public(모두에게), private(자기자신만), protected(상속 계층까지만)
	// 공개 함수(Method) = Message
public:
	//Player() = default; // 기본 생성자(no parameter), 컴파일러가 자동 생성
	//~Player() = default;
	Player();
	~Player();

	void Move(int inX, int inY);

private:
	int x = 0;
	int y = 0;
	int speed = 0;
};