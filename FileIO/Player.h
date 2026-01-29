#pragma once

enum class VariableType
{
	Int,
	Float,
	Enum,
	String,
	Unknown
};

template<typename T, VariableType Type>
class Variable
{
public:
	T GetValue();

private:
	char* name = nullptr;
	//VariableType type = VariableType::Unknown;
	VariableType type = Type;
	void* data = nullptr;
};

class Player
{
public:
	Player();
	Player(int id, int score, float attack);
	~Player();

	// to file
	void Serialize(const char* path);
	// from file
	void Deserialize(const char* path);
private:
	//Variable idVariable;
	int score = 0;
	int id = 0;
	float attack = 0.0f;
};
