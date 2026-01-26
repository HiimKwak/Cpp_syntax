#include <iostream>

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
	void CreateAccount()
	{
		char name[100];
		std::cout << "성함을 입력하세요 : ";
		std::cin >> name;
		accountList[id] = new Account(id, name);
		std::cout << "계좌가 성공적으로 개설되었습니다!" << std::endl;
		accountList[id]->RetrieveAccountInfo();
		++id;
	}
	void Deposit()
	{
	}
	void Withdraw()
	{

	}
	void Inquire()
	{

	}
private:
	Account* accountList[100];
	int id = 0;
};

int main()
{
	Bank bank;
	bank.CreateAccount();

	std::cin.get();
}