#include <iostream>
#include <conio.h>

const int bankLimit = 100;

class Account
{
public:
	Account(int id, char* name)
		: id(id) {
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
		balance = 0;
	};

	Account(const Account& other)
		: id(other.id)
	{
		size_t length = strlen(other.name) + 1;
		name = new char[length];
		strcpy_s(name, length, other.name);
		balance = 0;
	}

	~Account()
	{
		delete[] name;
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
		else
		{
			std::cout << "잔액보다 큰 금액은 인출할 수 없습니다. 잔액: " << balance << "원" << std::endl;
		}
	}
	// 접근자: 목록 출력 및 안전한 외부 조회용
	const char* GetName() const { return name ? name : ""; }
	int GetId() const { return id; }
	int GetBalance() const { return balance; }

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
	}
	~Bank()
	{
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
	Account* CreateAccount()
	{
		if (id >= bankLimit)
		{
			std::cout << "더 이상 계좌를 생성할 수 없습니다 (한도 도달).\n";
			return nullptr;
		}

		char name[100];
		std::cout << "성함을 입력하세요 : ";
		std::cin >> name;
		accountList[id] = new Account(id, name);
		std::cout << "계좌가 성공적으로 개설되었습니다!" << std::endl;
		accountList[id]->RetrieveAccountInfo();
		Account* created = accountList[id];
		++id;
		return created;
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
		if (id == 0)
		{
			std::cout << "등록된 계좌가 없습니다.\n";
			return;
		}
		for (int i = 0; i < id; ++i)
		{
			accountList[i]->RetrieveAccountInfo();
		}
	}
	// 새로 추가한 헬퍼들
	int GetAccountCount() const
	{
		return id;
	}
	Account* GetAccount(size_t index)
	{
		return (index < static_cast<size_t>(id))
			? accountList[index]
			: nullptr;
	}
	void ListAccounts() const
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
private:
	int id = 0;
	Account* accountList[bankLimit] = { };
};

int main()
{
	bool isRunning = true;
	Bank* bank = new Bank();
	Account* currentAccount = nullptr;

	int amount;

	while (isRunning)
	{
		std::cout
			<< "1. 계좌개설\n"
			<< "2. 계좌선택\n"
			<< "3. 선택한 계좌로 입금\n"
			<< "4. 선택한 계좌로 출금\n"
			<< "5. 전체 고객 잔액 조회\n"
			<< "q. 종료\n"
			<< "원하시는 메뉴의 문자를 입력해주세요: \n";

		char input = _getch();

		switch (input)
		{
		case '1':
			std::cout << "입력: 1\n";
			currentAccount = bank->CreateAccount();
			std::cout << "******************************************\n";
			break;
		case '2':
			std::cout << "입력: 2\n";
			bank->ListAccounts();
			if (bank->GetAccountCount() == 0) break;
			std::cout << "선택할 계좌의 인덱스를 입력하세요: ";
			{
				size_t idx;
				if (!(std::cin >> idx))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "유효한 인덱스를 입력하세요.\n";
					break;
				}
				Account* sel = bank->GetAccount(idx);
				if (!sel)
				{
					std::cout << "해당 인덱스의 계좌가 없습니다.\n";
				}
				else
				{
					currentAccount = sel;
					std::cout << "인덱스 " << idx << " 계좌가 선택되었습니다. 계좌 정보:\n";
					currentAccount->RetrieveAccountInfo();
				}
			}
			break;
		case '3':
			std::cout << "입력: 3\n";
			if (!currentAccount)
			{
				std::cout << "선택된 계좌가 없습니다. 먼저 계좌를 선택하거나 생성하세요.\n";
				break;
			}
			std::cout << "입금액을 입력하세요: ";
			if (!(std::cin >> amount))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "유효한 숫자를 입력하세요.\n";
				break;
			}
			bank->Deposit(*currentAccount, amount);
			std::cout << "******************************************\n";
			break;
		case '4':
			std::cout << "입력: 4\n";
			if (!currentAccount)
			{
				std::cout << "선택된 계좌가 없습니다. 먼저 계좌를 선택하거나 생성하세요.\n";
				break;
			}
			std::cout << "출금액을 입력하세요: ";
			if (!(std::cin >> amount))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "유효한 숫자를 입력하세요.\n";
				break;
			}
			bank->Withdraw(*currentAccount, amount);
			std::cout << "******************************************\n";
			break;
		case '5':
			std::cout << "입력: 5\n";
			bank->Inquire();
			std::cout << "******************************************\n";
			break;
		case 'q':
			std::cout << "입력: q\n";
			std::cout << "프로그램을 종료합니다.\n";

			delete bank;
			bank = nullptr;
			currentAccount = nullptr;
			isRunning = false;

			break;
		default:
			std::cout << "잘못된 입력입니다. 다시 입력해주세요.\n";

			continue;
		}
	}
}