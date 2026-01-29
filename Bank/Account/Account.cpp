#include <iostream>
#include "Account.h"

Account::Account(int id, char* name)
{
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
	balance = 0;
}

Account::Account(const Account& other)
{
	size_t length = strlen(other.name) + 1;
	name = new char[length];
	strcpy_s(name, length, other.name);
	balance = 0;
}

Account::~Account()
{
	delete[] name;
	name = nullptr;
}

void Account::GetInfo() const
{
	std::cout << "계좌 ID: " << id << std::endl;
	std::cout << "이름: " << name << std::endl;
	std::cout << "잔액: " << balance << "원" << std::endl;
}

Account* Account::Create()
{
	char name[100];
	std::cout << "성함을 입력하세요 : ";
	std::cin >> name;
	Account* created = new Account(id, name);
	std::cout << "계좌가 성공적으로 개설되었습니다!" << std::endl;
	return created;
}

void Account::Deposit(int amount)
{
	balance += amount;
	std::cout << amount << "원을 입금하였습니다.\n" << "잔액: " << balance << "원" << std::endl;
}

void Account::Withdraw(int amount)
{
	if (amount <= balance)
	{
		balance -= amount;
		std::cout << amount << "원을 인출하였습니다.\n" << "잔액: " << balance << "원" << std::endl;
	}
	else
	{
		std::cout << "잔액보다 큰 금액은 인출할 수 없습니다. 잔액: " << balance << "원" << std::endl;
	}
}