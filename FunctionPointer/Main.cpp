#include <iostream>
#include <functional>

//typedef int (*Add)(int, int);
using Adder = int (*)(int a, int b);
//using Adder = std::function<int(int, int)>;
using ClassAdder = int (Operator::*)(int a, int b);

int A(int a, int b, Adder adder)
//int A(int a, int b, std::function<int(int, int)> adder)
{
	return adder(a, b);
}

int B(int a, int b, ClassAdder adder)
//int A(int a, int b, std::function<int(int, int)> adder)
{
	return adder(a, b);
}

int Add(int a, int b)
{
	return a + b;
}

class Operator
{
public:
	int Add(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	//int (*FunctionPointer)();
	//FunctionPointer = A;

	Operator oper;
	//ClassAdder adder = &Operator::Add;
	//std::cout << A(10, 20, Add) << '\n'; // Operator::Add는 안됨. 함수포인터는 일반함수를 위한 문법
	std::cout << B(10, 20, Add);

	std::cin.get();
}