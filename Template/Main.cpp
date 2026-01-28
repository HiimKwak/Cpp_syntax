#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void Swap(float& a, float& b) // function overloading
{
	float temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);

	float af = 10.f;
	float bf = 20.f;
	Swap(af, bf);

	std::cin.get();
}