#include <iostream>

// 매크로 안에서 #을 붙이면 무조건 문자열로 변환시킴
// ## 두 개면 토큰을 합침
#define NAME(x) #x

class Entity
{
public: 
	//const char* GetName() const { return "Entity"; }
	virtual const char* GetName() const { return NAME(Entity); }
};

class Player : public Entity
{
public:
	Player(const char* name)
	{
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}

	~Player()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}

	virtual const char* GetName() const	override { return name; } // virtual & override가 없어도 함수이름이 같고 형이 같으면 자동으로 오버라이딩 해준다.

private:
	char* name = nullptr;
};

int main()
{
	Entity* entities[250] = {};

	Entity* entity = new Entity();
	std::cout << entity->GetName() << std::endl;
	entities[0] = entity;

	//Player* player = new Player("Miles");
	Entity* player = new Player("Miles");
	std::cout << player->GetName() << std::endl;
	entities[1] = player;

	delete entity;
	delete player;

	std::cin.get();
}