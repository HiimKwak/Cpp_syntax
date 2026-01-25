#pragma once

class Circle
{
public:
	Circle(double r)
		: radius(r)
	{
	}
	double GetArea() const
	{
		return PI * radius * radius;
	}
	double GetGirth() const
	{
		return 2 * PI * radius;
	}
private:
	double radius;
	const double PI = 3.14159265358979323846;
};