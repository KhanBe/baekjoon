#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n = 0;
int m = 0;
vector<int> list[101];
int visited[101];
int answer = 0;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i];

			if (visited[next]) continue;

			q.push(next);
			visited[next] = true;
			answer++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}

	bfs(1);

	cout << answer;
}