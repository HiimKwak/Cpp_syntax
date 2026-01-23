#pragma once

// Forward declaration of the Entity class
class Vector;
class Entity
{
public:
	Entity() = default;
	Entity(int x, int y);
	// 복사 생성자(Copy Constructor)
	Entity(const Entity& other);
	~Entity();

private:
	Vector* position = nullptr; // Vector position; 쓰면 실제 크기를 알아야해서 include 필요
	};