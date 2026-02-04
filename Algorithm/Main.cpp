#include <iostream>
#include <vector>

#include "Queue/Queue2.h"

int main()
{
	int bridge_weight = 2;
	int weight = 10;
	std::vector<int> truck_weights = { 7,4,5,6 };

	Queue2 queue;
	queue.solution(bridge_weight, weight, truck_weights);
}