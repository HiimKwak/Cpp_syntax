#include <iostream>
#include <conio.h>

#include "Bank/Bank.h"
#include "Account/Account.h"

const int bankLimit = 100;

int main()
{
	bool isRunning = true;
	Bank* bank = new Bank();
	Account* currentAccount = nullptr;

	int amount;

	while (isRunning)
	{
		std::cout
			<< "******************************************\n"
			<< "1. 계좌개설\n"
			<< "2. 계좌선택\n"
			<< "3. 선택한 계좌로 입금\n"
			<< "4. 선택한 계좌로 출금\n"
			<< "5. 전체 고객 잔액 조회\n"
			<< "q. 종료\n"
			<< "******************************************\n"
			<< "원하시는 메뉴의 문자를 입력해주세요: \n";

		char input = _getch();

		switch (input)
		{
		case '1':
			std::cout << "입력: 1\n";
			bank->CreateAccount();

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
					currentAccount->GetInfo();
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