#include <iostream>
#include <vector>
#include <utility>

void Hanoi(int n, int start, int destination, int open, std::vector<std::pair<int, int>>& logs)
{
	if (n > 0)
	{
		Hanoi(n - 1, start, open, destination, logs);
		std::pair<int, int> p = std::make_pair(start, destination);
		logs.push_back(p);
		Hanoi(n - 1, open, destination, start, logs);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, count;
	std::cin >> n;

	std::vector<std::pair<int, int>> logs;

	Hanoi(n, 1, 3, 2, logs);

	std::vector<std::pair<int, int>>::iterator it;
	std::cout << logs.size() << "\n";
	for (it = logs.begin(); it != logs.end(); ++it)
	{
		std::cout << *it.first << " " << *it.second << "\n";
	}
	return 0;
}