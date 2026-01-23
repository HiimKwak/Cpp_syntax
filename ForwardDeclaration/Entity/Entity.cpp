#include "Entity.h"
#include "../Vector.h"
// 꺽쇠는 시스템 디렉토리에서 찾음. ""는 시스템 + 현재 디렉토리에서 찾음
// 프로젝트 속성 - VC++ directories - Include Directories에 경로
// 꺽쇠에 추가하고 싶다면 프로젝트 속성 - C/C++ - General - Additional Include Directories에 경로 추가
// $(ProjectDir)\;$(ProjectDir)\Entity; 매크로(상대경로), 절대경로로 하면 깨질 수 있음

Entity::Entity(int x, int y)
{
	position = new Vector(x, y);
	position->x = x; // (*position).x = x;
	position->y = y;
}

Entity::~Entity()
{
	if (position != nullptr)
	{
		delete position;
		position = nullptr;
	}
}