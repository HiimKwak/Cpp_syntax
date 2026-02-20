#include "Queue4.h"
#include <iostream>
#include <queue>

int Queue4::CardThrow()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::queue<int> q;
	
	int number;
	std::cin >> number;

	for (int i = 1; i <= number; i++)
		q.push(i);
	
	while (q.size() > 1)
	{
		q.pop();
		int front = q.front();
		q.pop();
		q.push(front);
	}
	
	std::cout << q.front();

	return 0;
}
