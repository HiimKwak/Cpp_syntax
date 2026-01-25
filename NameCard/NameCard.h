#pragma once
#include <iostream>

class NameCard
{
public:
	NameCard(const char* name, const char* phone, const char* email, const char* job)
	{
		// name
		size_t length = strlen(name) + 1;
		m_name = new char[length];
		strcpy_s(m_name, length, name);
		// phone
		length = strlen(phone) + 1;
		m_phone = new char[length];
		strcpy_s(m_phone, length, phone);
		// email
		length = strlen(email) + 1;
		m_email = new char[length];
		strcpy_s(m_email, length, email);
		// job
		length = strlen(job) + 1;
		m_job = new char[length];
		strcpy_s(m_job, length, job);
	}
	~NameCard()
	{
		if (m_name)
		{
			delete[] m_name;
			m_name = nullptr;
		}
		if (m_phone)
		{
			delete[] m_phone;
			m_phone = nullptr;
		}
		if (m_email)
		{
			delete[] m_email;
			m_email = nullptr;
		}
		if (m_job)
		{
			delete[] m_job;
			m_job = nullptr;
		}
	}

	void ShowData() const
	{
		printf("이    름: %s\n", m_name);
		printf("전화번호: %s\n", m_phone);
		printf("이 메 일: %s\n", m_email);
		printf("직    업: %s\n", m_job);
	}
private:
	char* m_name = nullptr;
	char* m_phone = nullptr;
	char* m_email = nullptr;
	char* m_job = nullptr;
};