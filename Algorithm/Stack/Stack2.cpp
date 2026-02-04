#include <string>
#include <vector>

#include "Stack2.h"

using namespace std;

Stack2::Stack2(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;

	// 7, 3, 9
	// 5 10 1 1 20 1 -> 이것도 이 배열 구한다음에 이전값보다 큰 숫자가 나올 때만 추가하면 되네
	// 1. 소요시간(스토리 포인트) 배열 구하기
	vector<int> storyPoints;
	for (int idx = 0; idx < progresses.size(); ++idx)
	{
		int left = 100 - progresses[idx];
		int quotient = left / speeds[idx];
		float remainder = left % speeds[idx];
		if (remainder > 0)
			quotient += 1;
		storyPoints.push_back(quotient);
	}

	// 2. 소요시간 순회하면서 배포 스택 만들기
	vector<int> deployList;
	int previous = 0;
	for (int idx = 0; idx < storyPoints.size(); idx++)
	{
		int current = storyPoints[idx];
		if (deployList.empty())
		{
			deployList.push_back(current);
			previous = current;
			continue;
		}

		if (previous >= current)
		{
			deployList.push_back(current);
		}

		if (previous < current || idx == storyPoints.size() - 1)
		{
			// 배포 발사
			answer.push_back(deployList.size());
			deployList.clear();
			deployList.push_back(current);
			previous = current;
		}

	}

	//return answer;
}