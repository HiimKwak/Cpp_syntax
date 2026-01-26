#include <iostream>

class Entity
{
public:
	Entity()
	{
		std::cout << "Entity() called" << std::endl;
	}
	~Entity()
	{
		std::cout << "~Entity() called" << std::endl;
	}
protected:
	float x = 0.0f;
	float y = 0.0f;
};

class Player : public Entity
{
public:
	Player()
	{
		std::cout << "Player() called" << std::endl;
	}
	~Player()
	{
		std::cout << "~Player() called" << std::endl;
	}
private:
	char* name = nullptr;
};

int main()
{
	Player player;

	std::cin.get();
}