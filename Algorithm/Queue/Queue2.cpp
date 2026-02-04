#include "Queue2.h"

#include <vector>
#include <iostream>

int Queue2::solution(int bridge_length, int weight, std::vector<int> truck_weights)
{
	// 경과시간 = for loop 횟수
	int count = 0;
	std::vector<int> bridge;
	//std::cout << truck_weights.size();

	while (truck_weights.size() != 0)
	{
		// 일단 다리에 올리기
		bridge.push_back(truck_weights.front());
		truck_weights.erase(truck_weights.begin());

		int bridge_weights = 0;
		for (int id = 0; id < bridge.size(); ++id)
		{
			bridge_weights += bridge[id];
		}

		// 만약 길이를 넘거나, 무게를 넘으면 넣었던거 다시 빼고 맨 앞꺼 내리기
		if (bridge.size() > bridge_length || bridge_weights >= weight)
		{
			int revert = bridge.back();
			truck_weights.insert(truck_weights.begin(), revert);
			bridge.pop_back();
			bridge.erase(bridge.begin());
		}

		count++;
	}

	return count;
}
