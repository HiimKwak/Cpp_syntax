#include <iostream>

// Macro << 최근들어 지양함. 중첩된 매크로는 디버깅을 어렵게 함
//#define Square(x) ((x) * (x))

// 인라인 함수 -> 속도 때문에 씀. 대신 용량을 포기
#define FORCEINLINE __forceinline

FORCEINLINE int Square(int x)
{
	return x * x;
}

int main()
{
	int number = Square(10);
}