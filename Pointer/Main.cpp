#include <iostream>

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
	// 동적 할당.
	char* buffer = new char[10];

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