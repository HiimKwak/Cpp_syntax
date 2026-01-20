#include <iostream>
#include "Log.h" // void Log(const char* message);로 치환됨

// F12. Ctrl + - : 참조/돌아가기
// Ctrl + 방향키 좌우 : 
// Home + End + Shift : 
// Alt + Shit + 방향키 : 여러 줄 동시 선택
int main()
{
	Log("Hello World");

	//std::cout << "Hello World\n";
	// 프로그램 바로 종료되지 않게 하는 코드
	std::cin.get();
}