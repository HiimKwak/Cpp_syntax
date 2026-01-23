#include "Entity.h"
#include "../Vector.h"
// 꺽쇠는 시스템 디렉토리에서 찾음. ""는 시스템 + 현재 디렉토리에서 찾음
// 프로젝트 속성 - VC++ directories - Include Directories에 경로
// 꺽쇠에 추가하고 싶다면 프로젝트 속성 - C/C++ - General - Additional Include Directories에 경로 추가
// $(ProjectDir)\;$(ProjectDir)\Entity; 매크로(상대경로), 절대경로로 하면 깨질 수 있음
#include <iostream>

//using namespace ForwardDeclaration::A::B; // namespace 중첩 가능

Entity::Entity(int x, int y)
{
	position = new Vector(x, y);
	position->x = x; // (*position).x = x;
	position->y = y;
}

Entity::Entity(const Entity& other)
{
	std::cout << "copy constructor called" << std::endl;
	// 내 멤버변수에 other 멤버변수 값을 복사 << 복사 생성자의 기초
	//position = other.position; // 나중에 댕글링 포인터 문제 발생(미아 발생), 삭제된 메모리 주소에 접근
	// 포인터(힙) 주소를 복사하다보니 앞에서 먼저 삭제되면 접근 불가 문제가 생김(얕은 복사)

	// 깊은 복사(Deep Copy) : 공간 확보 -> 값 복사
	position = new Vector();
	position->x = other.position->x;
	position->y = other.position->y;
}

Entity::~Entity()
{
	if (position != nullptr)
	{
		delete position;
		position = nullptr;
	}
}