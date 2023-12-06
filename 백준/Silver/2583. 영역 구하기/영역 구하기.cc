#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, k;
int answer = 0;
char board[101][101];
bool visited[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };

vector<int> v;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	int size = 1;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (!(0 <= nextX && nextX < m) || !(0 <= nextY && nextY < n)) continue;
			if (!visited[nextX][nextY]) {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
				size++;
			}
		}
	}
	v.push_back(size);
	answer++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n >> k;
	for (int q = 0; q < k; q++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				visited[j][i] = true;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	cout << answer << "\n";
	sort(v.begin(), v.end());
	for (auto vv : v) cout << vv << " ";

	return 0;
}
