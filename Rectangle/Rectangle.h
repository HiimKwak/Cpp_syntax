#pragma once

class Rectangle
{
public:
	Rectangle(int w, int h)
		: width(w), height(h)
	{
	}
	int GetArea() const
	{
		return width * height;
	}
	int GetGirth() const
	{
		return 2 * (width + height);
	}
private:
	int width;
	int height;
};