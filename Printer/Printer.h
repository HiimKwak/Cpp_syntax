#pragma once
#include <iostream>

class Printer
{
public:
	Printer() = default;
	~Printer()
	{
		if (m_str)
		{
			delete[] m_str;
			m_str = nullptr;
		}
	}
	void SetString(const char* str)
	{
		// 기존에 멤버 변수에 문자열이 할당돼 있었다면 메모리 해제
		delete[] m_str; 
		if (!str) 
		{ 
			m_str = nullptr; 
			return; 
		}
		
		// 매개변수 문자열을 멤버 변수에 복사할 땐 다음 절차를 따른다
		//1. 매개변수 str의 길이를 알아낸다
		size_t length = strlen(str) + 1;
		//2. 그 길이만큼의 메모리를 동적 할당한다
		m_str = new char[length];
		//3. 매개변수 str의 내용을 멤버 변수에 복사한다
		strcpy_s(m_str, length, str);
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
	char* m_str = nullptr;
};