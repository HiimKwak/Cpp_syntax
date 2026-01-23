#pragma once
#include <iostream>

class Printer
{
public:
	void SetString(const char* str)
	{
		m_str = str;
	}
	void ShowString()
	{
		if (m_str)
		{
			std::cout << m_str << std::endl;
		}
		else
		{
			std::cout << "Can't show the string value" << std::endl;
		}
	}
private:
	char* m_str;
};