#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;
bool visited[1001];
vector<int> node[1001];

void bfs(int start) {
	if (visited[start]) return;

	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		for (int i = 0; i < node[curNode].size(); i++) {
			int nextNode = node[curNode][i];
			if (!visited[nextNode]) {
				visited[nextNode] = true;
				q.push(nextNode);
			}
		}
	}

	answer++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		node[u].push_back(v);
		node[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	cout << answer;
	return 0;
}
