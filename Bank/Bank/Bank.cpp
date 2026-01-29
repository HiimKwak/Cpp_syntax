#include <iostream>

#include "../Account/Account.h"
#include "Bank.h"

Bank::Bank() {
	for (int i = 0; i < limit; ++i)
		accountList[i] = nullptr;
}

Bank::~Bank() {
	if (accountList)
	{
		// delete[] accountList는 틀린 코드
		// accountList는 Account 객체 포인터 배열의 '첫 요소' 주소를 가리킴
		for (int i = 0; i < id; ++i) // 생성된 id까지만 순회
		{
			delete accountList[i];
			accountList[i] = nullptr;
		}
	}
}

void Bank::CreateAccount()
{
	if (id >= limit)
	{
		std::cout << "더 이상 계좌를 생성할 수 없습니다 (한도 도달).\n";
		return;
	}

	accountList[id] = new Account();
	accountList[id]->Create();
	accountList[id]->GetInfo();

	++id;
}

void Bank::Deposit(Account& account, int amount)
{
	account.Deposit(amount);
}

void Bank::Withdraw(Account& account, int amount)
{
	account.Withdraw(amount);
}
void Bank::Inquire()
{
	if (id == 0)
	{
		std::cout << "등록된 계좌가 없습니다.\n";
		return;
	}
	for (int i = 0; i < id; ++i)
	{
		accountList[i]->GetInfo();
	}
}

Account* Bank::GetAccount(size_t index) const
{
	return (index < static_cast<size_t>(id))
		? accountList[index]
		: nullptr;
}

void Bank::ListAccounts() const
{
	if (id == 0)
	{
		std::cout << "등록된 계좌가 없습니다.\n";
		return;
	}
	std::cout << "---- 계좌 목록 ----\n";
	for (int i = 0; i < id; ++i)
	{
		std::cout << "인덱스: " << i << ", 계좌ID: " << accountList[i]->GetId()
			<< ", 이름: " << accountList[i]->GetName()
			<< ", 잔액: " << accountList[i]->GetBalance() << "원\n";
	}
	std::cout << "------------------\n";
}