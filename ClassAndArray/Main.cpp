#include <iostream>

// 클래스는 새로운 자료형.
// 게임 물체(객체) - GameObject(Unity)/Actor(Unreal)/Entity(Quake)
class Entity
{
public:
	Entity()
	{
		std::cout << "Constructor called\n";
	}
	~Entity() = default;

	void ShowName() const // 함수를 상수형으로. 멤버변수를 건드리지 않는다는 보장
	{
		std::cout << "Entity showed up\n";
	}

	Entity* GetSelf()
	{
		// this는 자기 자신을 가리키는 포인터
		return this;
	}
};

// void ShowName(Entity* entity)
// {
// 	...
// }

void SafeDelete(Entity** entity) // 매개변수도 스택에 잡힘. 같은 주소를 가리키지만 다른 변수임
{
	delete* entity;
	*entity = nullptr;
}

int main()
{
	// 코테 문제(어려움)
	//Entity* entity = nullptr;
	//entity->ShowName(); // 객체가 null인데 멤버함수가 실행되는 이유?
	// 어셈블리로 바뀔 때 void ShowName(Entity* entity)로 바뀜(C언어처럼)
	// 그래서 ShowName(entity)로 실행되는데, 이 때 객체 내부 변수나 메모리에
	// 접근하는 코드가 있으면 실행오류가 남

	//const int count = 5;
	//Entity entities[count];

	//// range-based loop(foreach)
	//for (const Entity& entity : entities)
	//{
	//	entity.ShowName();
	//}

	//const int count = 5;
	//Entity* entities[count];
	////memset(entities, 0, sizeof(Entity*) * count); // sizedof(Entity)로 하면 어떻게 될까?

	//for (int ix = 0; ix < count; ++ix)
	//{
	//	entities[ix] = new Entity();
	//}

	//for (Entity*& entity : entities) // Entity* entity -> 스택에 entity라는 이름의 entities[0]과 같은 주소를 가진 다른 변수가 생긴다
	//	// 그래서 그 주소의 내부 값을 바꾸려면 레퍼런스나 더블 포인터를 걸어줘야한다
	//{
	//	// SafeDelete(&entity);
	//	delete entity;
	//	entity = nullptr;
	//}

	Entity* entity = new Entity();
	std::cout << entity << "\n";
	std::cout << entity->GetSelf() << "\n";

	delete entity;

	std::cin.get();
}