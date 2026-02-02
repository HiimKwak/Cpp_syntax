#include "Stack.h"

#include <iostream>
#include <vector>

std::vector<int> Stack1(std::vector<int> arr)
{
	std::vector<int> answer;

	// answer를 스택으로 사용하고, arr를 순회하면서 answer 맨 위 값이 다를 때만 answer에 삽입한다
	for (const int item : arr)
	{
		if (answer.empty())
		{
			answer.push_back(item);
		}

		if (answer.back() != item)
		{
			answer.push_back(item);
		}
	}

	std::cout << "[";
	for (auto& item : answer)
	{
		std::cout << item << ", ";
	}
	std::cout << "]\n";

	return answer;
}