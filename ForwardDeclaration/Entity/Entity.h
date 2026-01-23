#pragma once

// Forward declaration of the Entity class
class Vector;
class Entity
{
public:
	Entity(int x, int y);
	~Entity();

private:
	Vector* position = nullptr; // Vector position; 쓰면 실제 크기를 알아야해서 include 필요
};