#pragma once

class Account;

class Bank
{

public:
	Bank();
	~Bank();

	void CreateAccount();
	void Deposit(Account& account, int amount);
	void Withdraw(Account& account, int amount);
	void Inquire();

	// 새로 추가한 헬퍼들
	int GetAccountCount() const
	{
		return id;
	};
	Account* GetAccount(size_t index) const;
	void SetSelectedAccount(Account* account)
	{
		selectedAccount = account;
	};
	void ListAccounts() const;

private:
	int id = 0;
	const int limit = 100;
	Account* accountList[100] = { };
	Account* selectedAccount = nullptr;
};
