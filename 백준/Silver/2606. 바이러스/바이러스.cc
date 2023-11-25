#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define INF 987654321

using namespace std;

vector<int> node[101];
bool visited[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	//============================

	queue<int> q;

	q.push(1);
	visited[1] = true;

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

	int answer = -1;
	for (auto v : visited) answer += v;

	cout << answer;
	return 0;
}