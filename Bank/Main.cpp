#include <iostream>
#include <Windows.h>

class Account
{
public:
	Account(int id, char* name)
		: id(id), name(name) {
	};

	Account(const Account& other)
		: id(id)
	{
		size_t length = strlen(other.name) + 1;
		name = new char[length];
		strcpy_s(name, length, other.name);
	}

	~Account()
	{
		delete name;
		name = nullptr;
	}

	void RetrieveAccountInfo() const
	{
		std::cout << "계좌 ID: " << id << std::endl;
		std::cout << "이름: " << name << std::endl;
		std::cout << "잔액: " << balance << "원" << std::endl;
	}

	void Deposit(int amount)
	{
		balance += amount;
		std::cout << amount << "원을 입금하였습니다.\n" << "잔액: " << balance << "원" << std::endl;
	}
	void Withdraw(int amount)
	{
		if (amount <= balance)
		{
			balance -= amount;
			std::cout << amount << "원을 인출하였습니다.\n" << "잔액: " << balance << "원" << std::endl;
		}
		std::cout << "잔액보다 큰 금액은 인출할 수 없습니다. 잔액: " << balance << "원" << std::endl;
	}

protected:
	int id;
	char* name = nullptr;
	int balance = 0;
};

class Bank
{
public:
	Bank()
	{
		memset(accountList, 0, sizeof(Account*) * 100);
	}
	~Bank()
	{
		if (accountList)
		{
			// delete[] accountList는 틀린 코드
			// accountList는 Account 객체 포인터 배열의 '첫 요소' 주소를 가리킴
			for (size_t i = 0; i < 100; ++i)
			{

				delete accountList[i];
				accountList[i] = nullptr;
			}
		}
	}
	Account* CreateAccount()
	{
		char name[100];
		std::cout << "성함을 입력하세요 : ";
		std::cin >> name;
		accountList[id] = new Account(id, name);
		std::cout << "계좌가 성공적으로 개설되었습니다!" << std::endl;
		accountList[id]->RetrieveAccountInfo();
		++id;
		return accountList[id];
	}
	void Deposit(Account& account, int amount)
	{
		account.Deposit(amount);
	}
	void Withdraw(Account& account, int amount)
	{
		account.Withdraw(amount);
	}
	void Inquire()
	{
		for (const Account* account : accountList)
		{
			account->RetrieveAccountInfo();
		}
	}
private:
	Account* accountList[100];
	int id = 0;
};

int main()
{
	bool isRunning = true;
	Bank* bank = new Bank();

	while (isRunning)
	{

		std::cout
			<< "1. 계좌개설\n"
			<< "2. 입금\n"
			<< "3. 출금\n"
			<< "4. 전체 고객 잔액 조회계좌개설\n"
			<< "q. 종료"
			<< "원하시는 메뉴의 문자를 입력해주세요: "
			<< std::endl;

		Account* newAccount = bank->CreateAccount();
		bank->Deposit(*newAccount, 1);
	}

	std::cin.get();
}