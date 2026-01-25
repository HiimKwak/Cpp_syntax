#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

int main()
{
	Rectangle rect = Rectangle(3, 4);    // Rectangle(가로길이, 세로길이)
	std::cout << "면적: " << rect.GetArea() << "\n";
	std::cout << "둘레: " << rect.GetGirth() << "\n";

	Circle circle = Circle(5);    // Circle(원의 반지름)
	std::cout << "면적: " << circle.GetArea() << "\n";
	std::cout << "둘레: " << circle.GetGirth() << "\n";
}