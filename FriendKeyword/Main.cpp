#include <iostream>

class Entity
{
public:
	friend void ShowEntity(Entity& entity) // 외부 함수를 먼저 선언하고, 클래스 내부에서 friend로 지정
	{
		std::cout << entity.x << ", " << entity.y << "\n";
	} // friend keyword 때문에 객체 안에 있을 뿐 외부 함수임
	// 취지는 이렇게 작성하자가 아니라 이렇게 작성돼있을 때 당황하지 말자는 것

	//void Add(Entity& other)
	//{
	//	x += other.x;
	//	y += other.y;
	//}
	//// 같은 Entity 클래스이므로 접근한정자가 private여도 접근 가능

	friend void Add(Entity& entity1, Entity& entity2)
	{
		entity1.x += entity2.x;
		entity1.y += entity2.y;
	}

private:
	int x = 0;
	int y = 0;
};

// 멤버함수 아님(범위지정 연산자 없음)
// void ShowEntity(Entity& entity)
// {
// 	std::cout << entity.x << ", " << entity.y << "\n";
// }

int main()
{
	Entity entity;
	ShowEntity(entity);
}