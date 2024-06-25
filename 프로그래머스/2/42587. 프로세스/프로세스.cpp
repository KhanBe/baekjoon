#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	queue<pair<int,int>> q;
	priority_queue<int> pq;

	for (int i = 0; i < priorities.size(); i++) {
		q.push({ i, priorities[i] });//[번째, 우선순위값]
		pq.push(priorities[i]);
	}

	int answer = 0;
	while (1) {

		pair<int, int> value = q.front();
		q.pop();

		if (pq.top() == value.second) {
			answer++;
			if (location == value.first) return answer;
			pq.pop();
		}
		else {
			q.push(value);
		}
	}



	return answer;
}