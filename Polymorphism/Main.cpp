#include <iostream>

// 매크로 안에서 #을 붙이면 무조건 문자열로 변환시킴
// ## 두 개면 토큰을 합침
#define NAME(x) #x
#define PURE = 0

// 추상클래스는 구현을 강제하고 싶을 때 사용
// = 인터페이스, 인터페이스는 순수 가상 함수만 가져야 함

class NameInterface
{
public: // 상속 관계가 아니더라도 외부에서 접근할 수 있어야 하므로 public을 사용해야 함
	// 순수 가상 함수
	virtual const char* GetName() const = 0;
	//virtual const char* GetName() const PURE; // 흠..
};

class Entity: public NameInterface
{
public: 
	//const char* GetName() const { return "Entity"; }
	virtual const char* GetName() const override { return NAME(Entity); }
};

class Player : public NameInterface
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

	Player* player = new Player("Miles");
	//Entity* player = new Player("Miles"); // __vfptr 조사식 조회 가능
	std::cout << player->GetName() << std::endl;
	//entities[1] = player;



	delete entity;
	delete player;

	std::cin.get();
}