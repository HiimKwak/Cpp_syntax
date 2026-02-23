#include <vector>
#include <iostream>
#include <utility>
#include <cstring>

std::vector<std::pair<int, int>> tree[10001];
bool visited[10001];
int max, end;

void dfs(int v, int sum)
{
	if (visited[v]) return;
	visited[v] = true;

	if (sum > max)
	{
		max = sum;
		end = v;
	}

	for (int i = 0; i < tree[v].size(); i++)
	{
		dfs(tree[v][i].first, sum + tree[v][i].second);
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	while (--n)
	{
		int p, c, w;
		std::cin >> p >> c >> w;
		tree[p].emplace_back(std::make_pair(c, w));
		tree[c].emplace_back(std::make_pair(p, w));
	}

	dfs(1, 0);

	std::memset(visited, false, sizeof(visited));
	dfs(end, 0);

	std::cout << max;

	return 0;
}
//1 : [{2, 3}, {3, 2}]
//2 : [{1, 3}, { 4, 5 }]
//3: [{1,2}, {5, 11}, {6, 9}]
//4: [{2, 5}, {7, 1}, {8,7}]
