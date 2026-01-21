#include <iostream>

// 배열을 함수에 전달
void PrintArray(int* array, int length)
{
	// size_t size = sizeof(array); // 배열의 크기를 추정할 수 있어보이지만 포인터의 저장공간 크기만 나온다
	// 원시배열 자체를 매개변수로 넘겨줄 수 있는 방법은 없다
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix] << "\n";
	}
}

int main()
{
	int array[10] = {};
	memset(array, 0, sizeof(int) * 10);

	array[0] = 1;
	array[3] = 10;
	array[9] = 100;

	// Out-Of-Index(Range)
	// array[10] = 1000; // 컴파일러가 막아줌

	// 배열의 이름은 주소(포인터)
	int* arrayPointer = array; // 첫번째 원소만 보여줌
	//arrayPointer[1] = 2;    // 두번째 원소에 접근 가능
	*(arrayPointer+1) = 2;    // 두번째 원소에 접근 가능

	// 배열 원소 전체 읽기(순회)
	// range-based loop
	//for (const int& item : array)
	//{
	//	std::cout << item << "\n";
	//}
	//// index loop
	//for (int ix =   0; ix < 10; ++ix)
	//{
	//	std::cout << array[ix] << "\n";
	//}
	PrintArray(array, 10);

	// 배열 동적 할당
	int* dynamicArray = new int[10];
	// 우측항: 힙 영역에 int 타입 요소 10개로 이루어진 연속된 배열을 동적 할당합니다.
	// 좌측항: 배열 전체의 주소가 아니라, 배열의 첫 번째 요소(&dynamicArray[0])의 주소를 가리키는 포인터입니다.
	memset(dynamicArray, 1, sizeof(int) * 10);
	for (int ix = 0; ix < 10; ++ix)
	{
		dynamicArray[ix] = ix * 1;
	}
	// 메모리 해제
	delete[] dynamicArray;

	std::cin.get();
