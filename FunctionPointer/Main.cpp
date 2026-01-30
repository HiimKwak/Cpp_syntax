//#include <iostream>
//#include <functional>
//
////typedef int (*Add)(int, int);
//using Adder = int (*)(int a, int b);
////using Adder = std::function<int(int, int)>;
//using ClassAdder = int (Operator::*)(int a, int b);
//
//int A(int a, int b, Adder adder)
////int A(int a, int b, std::function<int(int, int)> adder)
//{
//	return adder(a, b);
//}
//
//int B(int a, int b, ClassAdder adder)
////int A(int a, int b, std::function<int(int, int)> adder)
//{
//	return adder(a, b);
//}
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//class Operator
//{
//public:
//	int Add(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	//int (*FunctionPointer)();
//	//FunctionPointer = A;
//
//	Operator oper;
//	//ClassAdder adder = &Operator::Add;
//	//std::cout << A(10, 20, Add) << '\n'; // Operator::Add는 안됨. 함수포인터는 일반함수를 위한 문법
//	std::cout << B(10, 20, Add);
//
//	std::cin.get();
//}

#include <iostream>
#include <vector>
#include <algorithm>

class Less
{
public:
	bool operator()(int a, int b) // 호출 연산자 오버로딩
	{
		return a < b;
	}
};

class Greater
{
public:
	bool operator()(int a, int b) // 호출 연산자 오버로딩
	{
		return a > b;
	}
private:
	// 상태도 추가할 수 있음.
};

int main()
{
	std::vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	/*Less less;
	Greater greater;*/

	auto greater = [](int a, int b)->bool { return a > b; };

	int number1 = 10;
	int number2 = 5;

	bool result = greater(number1, number2);
	std::sort( // insertion sort, quick sort, heap sort 조합인 introsort로 구현돼있음
		array.begin(),
		array.end(),
		greater
	);

	int sum = 0;
	std::for_each(
		array.begin(),
		array.end(),
		[&sum](int item) {sum += item; }
	);

	std::cout << "Sum = " << sum << std::endl;

	for (const auto item : array)
	{
		std::cout << item << " ";
	}

	std::cout << std::endl;

	std::cin.get();
}