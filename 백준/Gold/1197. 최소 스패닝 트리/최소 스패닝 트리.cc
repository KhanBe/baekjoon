#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int v = 0, e = 0;
int min = 1000001;
int visited[10001];
int answer = 0;
vector<pair<int, int>> list[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {//입력
		int to, from, weight;
		cin >> to >> from >> weight;
		list[to].push_back({ weight, from });
		list[from].push_back({ weight, to });
	}
	
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		if (visited[cur.second]) continue;
		visited[cur.second] = true;
		answer += cur.first;

		pair<int, int> next;

		for (int i = 0; i < list[cur.second].size(); i++) {
			next = list[cur.second][i];

			if (visited[next.second]) continue;
			pq.push(next);

		}
	}
	
	cout << answer;
}