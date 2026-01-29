#pragma once

class Account
{
public:
	Account() = default;
	Account(int id, char* name)
		: id(id) {
	}

	Account(const Account& other)
		: id(other.id) {
	}

	~Account();

	void GetInfo() const;
	Account* Create();
	void Deposit(int amount);
	void Withdraw(int amount);

	const char* GetName() const { return name ? name : ""; }
	int GetId() const { return id; }
	int GetBalance() const { return balance; }

protected:
	int id;
	char* name = nullptr;
	int balance = 0;
};