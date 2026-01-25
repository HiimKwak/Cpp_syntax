#include <iostream>
#include "NameCard.h"

int main()
{
	// NameCard (이름, 전화번호, 이메일, 직업)
	// NameCard kwak("Mingyu Kwak", "010-000-0000", "abd@def.com", "Game Dev");
	// kwak.ShowData();
	const int count = 3;
	NameCard* nameCards[count] = { };

	char name[100];
	char phone[100];
	char email[100];
	char job[100];

	for (int ix = 0; ix < count; ++ix)
	{
		std::cout << "name : ";
		std::cin >> name;
		std::cout << "phone : ";
		std::cin >> phone;
		std::cout << "email : ";
		std::cin >> email;
		std::cout << "job : ";
		std::cin >> job;

		nameCards[ix] = new NameCard(name, phone, email, job);
	}
	for (int ix = 0; ix < count; ++ix)
	{
		nameCards[ix]->ShowData();
		std::cout << "------------------\n";
	}
	for (int ix = 0; ix < count; ++ix)
	{
		delete nameCards[ix];
	}
}