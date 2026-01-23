#pragma once

class Calculator
{
public:
	Calculator() = default;
	~Calculator() = default;

	int Add(int x, int y)
	{
		addCount++;
		return x + y;
	}

	float Divide(int x, int y)
	{
		divideCount++;
		return (float)x / (float)y;
	}

	int Substract(int x, int y)
	{
		substractCount++;
		return x - y;
	}

	int Multiply(int x, int y)
	{
		multiplyCount++;
		return x * y;
	}

	void ShowOperationCount();

private:
	int addCount = 0;
	int divideCount = 0;
	int substractCount = 0;
	int multiplyCount = 0;
};