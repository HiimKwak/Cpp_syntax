#include <iostream>

class Point
{
public:
	Point(int x = 0, int y = 0)
		: x(x), y(y)
	{
	}

	// 덧셈 v1
	/*Point Add(const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}*/
	// 덧셈 v2(비멤버(외부)함수 - 원래 구현은 바깥에 있어야 함)
	friend Point Add(const Point& left, const Point& right)
	{
		return Point(left.x + right.x, left.y + right.y);
	}
	// 덧셈 v3(연산자 오버로딩)
	Point operator+(const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}
	// 덧셈 v3(비멤버(외부) 함수이기 때문에 파라미터가 2개 필요함)
	friend Point operator+(const Point& left, const Point& right)
	{
		return Point(left.x + right.x, left.y + right.y);
	}

	int operator[](int index)
	{
		return array[index];
	}
	int GetArrayValueWithIndex(int index)
	{
		return array[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& point)
	{
		return os << "(" << point.x << ", " << point.y << ")\n";
	}

public:
	int x = 0;
	int y = 0;
	int array[100] = {};
};

//std::ostream& operator<<(std::ostream& os, const Point& point)
//{
//	return os << "(" << point.x << ", " << point.y << ")\n";
//}

int main()
{
	Point p1(1, 1);
	Point p2(5, 5);

	//Point p3(p1.x + p2.x, p1.y + p2.y); v1
	//Point p3 = add(p1, p2); v2
	Point p3 = p1 + p2; // p1.operator+(p2)
	//int value = p3[3]; // p3.GetArrayValueWithIndex(3);

	//std::cout << p3.x << p3.y << std::endl;; = std::cout.operator<<(p3.x).operator<<(p3.y);
	std::cout << p3 << std::endl; // std::cout.operator<<(p3); operator<<(std::cout, p3);

	std::cin.get();
}