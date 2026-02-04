#include "Queue1.h"

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int Queue1::solution(vector<int> priorities, int location)
{
	queue<int> q;
	int count = 0;
	int order = location;
	for (int item : priorities)
		q.push(item);

	while (true)
	{
		queue<int> temp = q;
		int max = INT_MIN;
		while (!temp.empty())
		{
			max = max(max, temp.front());
			temp.pop();
		}
		int current = q.front();
		q.pop();
		if (current == max)
		{
			count++;
			if (order == 0) break;
		}
		else
		{
			q.push_back(current);
		}
		order = order == 0 ? q.size() - 1 : order - 1;
	}

	return count;
}