#include <iostream>
// #include <string> // string 헤더는 연습을 위해 사용 안함

// 클래스 내부에서 문자열 다루기
class Player
{
public: // 접근 한정자/제한자: 접근 가능한 범위 설정
	// constructor: 객체 생성 시 호출되는 특별한 함수. 반환형이 없고 클래스 이름과 동일
	Player(const char* inName)
	{
		// 문자열 복사
		// name = inName; // 올바르지 않은 방법
		// 1. 저장 공간 확보 = 공간의 크기부터 알아야 함
		// long long test = 1; == __int64 test = 1;
		size_t length = strlen(inName) + 1; // 내부 구현 = null이 나올 때까지 +1. 추가로 마지막에 1을 더해줘야 함
		name = new char[length];

		// 2. 문자열 복사
		/*for (int ix = 0; ix < length; ++ix)
		{
			name[ix] = inName[ix];
		}*/
		strcpy_s(name, length, inName); // memcpy()와 똑같다. 다만 문자열 길이 검증 한 번 더 하는 차이
	}

	// 소멸자: 객체가 해제될 때 실행됨
	~Player()
	{
		if (name) // if (name != nullptr)
		{
			delete[] name;
			name = nullptr; // 어차피 name도 player가 메모리 공간에서 해제되면서 사라질거라 필수는 아님
		}
	}
private:
	// 문자열을 저장할 변수
	char* name = nullptr;
};


int main()
{
	// string
	// 문자열은 불변성을 가진다
	// 문자열 합성, 변경 등의 액션이 많아지면 성능이 떨어지는 이유: 수정은 사실 기존 값을 폐기하고 새 값을 바인딩하는 행위 
	auto testString = "Miles"; // == const char *testString = "Miles";
	std::cout << testString << "\n";

	// 문자 배열도 가능
	char buffer[6] = { 'M', 'i', 'l', 'e', 's', '\0' }; // 0 또는 \0(null)이 배열 마지막에 들어가야함
	// 이유 : 문자열을 제대로 사용하려면 문자열의 끝 위치를 알아야 하는데 이를 위해 null 문자(\0)를 문자열 끝에 추가하는 것으로 약속했다.
	std::cout << buffer << "\n";

	// 객체 기반으로 문자열 사용
	Player player("Miles Davison");

	std::cin.get();
}