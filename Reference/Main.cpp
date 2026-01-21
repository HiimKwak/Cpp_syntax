#include <iostream>

//#define LOG(x) std::cout << x << std::endl

// Call by value: 값으로 호출(값만 복사됨)
// void Increment(int value)
// {
//	 ++value;
// }

// Call by reference: 참조로 호출
// 참조 = 주소 -> 주소 값 복사
// void Increment(int *value)
// {
// 	++(*value);
void Increment(int& value)
{
	++value;
}
 
int main()
{
	// int a = 5;
	// int& ref = a;
	// ref = 10;

	int number = 10;
	Increment(number);

	std::cin.get();
}