#include <iostream>

void PrintString(char* string)
{
	std::cout << string << std::endl;
}

class A
{
public:
	virtual void Test() {}
};
class B : public A {};

int main()
{
	const char* name = "Miles";
	PrintString(const_cast<char*>(name));

	int number = 10;
	float floatNumber = static_cast<float>(number);

	A* a = new A();
	B* b1 = static_cast<B*>(a);
	if (b1)
	{
		std::cout << "b1 is not null\n";
	}
	B* b2 = reinterpret_cast<B*>(a);
	if (b2)
	{
		std::cout << "b2 is not null\n";
	}
	B* b3 = dynamic_cast<B*>(a); // 다형성 필요(virtual-vtable)
	if (b3)
	{
		std::cout << "b3 is not null\n";
	}

	const type_info& aInfo = typeid(a);
	const type_info& bInfo = typeid(b1);
	std::cout << "Type of A is " << aInfo.name() << std::endl;
	if (aInfo == bInfo) // 주소값 비교
	{
		std::cout << "Same\n";
	}

	delete a;

	std::cin.get();
}