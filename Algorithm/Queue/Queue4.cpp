#include "Queue4.h"
#include <queue>

int Queue4::CardThrow(int number)
{
	std::queue<int> q;
	
	// 1부터 number까지 카드를 큐에 추가
	for (int i = 1; i <= number; i++)
	{
		q.push(i);
	}
	
	// 카드가 1장 남을 때까지 반복
	while (q.size() > 1)
	{
		q.pop();           // 맨 위 카드를 버림
		int front = q.front();
		q.pop();           // 다음 카드를 꺼내서
		q.push(front);     // 맨 뒤로 이동
	}
	
	// 마지막 남은 카드 반환
	return q.front();
}
