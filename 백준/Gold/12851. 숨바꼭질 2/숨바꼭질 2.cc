#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	bool visited[100004] = { 0, };

	int answer = 0, MinTime = 100000;
	int n = 0, k = 0;
	cin >> n >> k;

	visited[n] = true;
	pq.push({0, n});

	while (!pq.empty()) {
		int weight = pq.top().first;
		int curDot = pq.top().second;
		pq.pop();

		visited[curDot] = true;

		if (MinTime < weight) break;

		if (curDot == k) {
			MinTime = weight;
			if (weight == MinTime) answer++;
			continue;
		}

		if (0 <= curDot - 1 && !visited[curDot - 1])
			pq.push({ weight + 1, curDot - 1 });
		if (curDot + 1 <= 100000 && !visited[curDot + 1])
			pq.push({ weight + 1, curDot + 1 });
		if (curDot * 2 <= 100000 && !visited[curDot * 2])
			pq.push({ weight + 1, curDot * 2});
	}

	cout << MinTime << "\n" << answer;

	return 0;
}