#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define INF 987654321

using namespace std;

int visited[100001];
queue<int> q;

void bfs(int n, int k) {
	q.push(n);
	visited[n] = 0;

	int cycle = 0;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k) {
			cout << visited[k];
			return;
		}

		int dx[3] = { cur + 1, cur - 1, cur * 2 };
		for (int i = 0; i < 3; i++) {
			if (!(0 <= dx[i] && dx[i] <= 100000)) continue;
			if (visited[dx[i]] != INF) continue;

			visited[dx[i]] = visited[cur] + 1;
			q.push(dx[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	//초기화
	for (int i = 0; i <= 100000; i++) visited[i] = INF;

	bfs(n, k);




	return 0;
}