#include <iostream>
#include <deque>

void RotateLeft(std::deque<int> &dq)
{
	int front = dq.front();
	dq.pop_front();
	dq.push_back(front);
}

void RotateRight(std::deque<int> &dq)
{
	int back = dq.back();
	dq.pop_back();
	dq.push_front(back);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m, target;
	std::cin >> n >> m;
	
	std::deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	int count = 0;
	while (m--)
	{
		std::cin >> target;

		// 타겟의 위치 찾기
		int idx = 0;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == target)
			{
				idx = i;
				break;
			}
		}

		// 왼쪽/오른쪽 회전 거리 계산
		int leftDistance = idx;
		int rightDistance = dq.size() - idx;

		// 더 짧은 쪽으로 회전
		while (dq.front() != target)
		{
			leftDistance <= rightDistance ? RotateLeft(dq) : RotateRight(dq);
			++count;
		}

		dq.pop_front();
	}

	std::cout << count;

	return 0;
}