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
	Player(const char* inName);
	~Player();

	void Move(int inX, int inY);

private:
	int x = 0;
	int y = 0;
	int speed = 0;
	// 맨처음 Cpp 나왔을 땐 초기화 지원을 하지 않았음

	// 이름 저장하는 문자열 변수
	//char name[10] = {}; // 스택 변수, 최대글자수 제한(9) <- id같이 제한이 필요할 때
	char* name = nullptr; // 힙 변수
};