#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

void DeletePointer(void*& ptr)
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // _CrtDumpMemoryLeaks 함수 호출 설정

	//_CrtSetBreakAlloc(156);

	// todo 의도적 메모리 릭
	int *intPointer = new int;
	delete intPointer;

	// 동적 할당.
	//char* buffer = new char[10];

	// 포인터는 주소를 저장하는 변수.
	//void* pointer = nullptr;
	void* pointer = new int;
	DeletePointer(pointer);
	//delete pointer;
	//pointer = nullptr;

	// null check.
	if (pointer != nullptr)
	{
		std::cout << "Pointer is not null\n";
	}
	else
	{
		std::cout << "Pointer is null\n";
	}

	std::cin.get();
}