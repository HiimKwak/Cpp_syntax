#include <iostream>
#include <format>
#include "Calculator.h"

void Calculator::ShowOperationCount()
{
	std::cout << std::format("µ¡¼À: {}  »¬¼À: {}  °ö¼À: {}  ³ª´°¼À: {}",
		addCount, substractCount, multiplyCount, divideCount);
}