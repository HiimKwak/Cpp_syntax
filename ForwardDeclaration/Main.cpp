#include <iostream>
#include "./Entity/Entity.h"

void TestFunction(Entity entity)
{
	std::cout << "TestFunction called" << std::endl;
}
int main()
{
	Entity entity(10, 20);
	Entity entity2(entity); // 1¹ø
	Entity entity3 = entity2; // 1¹ø

	TestFunction(entity3); // 2¹ø

	std::cin.get();
}