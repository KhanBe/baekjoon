#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int node[501][501];
int visited[501][501];
int drawCount = 0;
int drawMax = 0;
int n = 0, m = 0;

int bfs(int length, int width) {
	queue<pair<int, int>> q;
	drawCount = 1;
	
	q.push({ length, width });
	visited[length][width] = true;
	
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextLength = cur.first + dx[i];
			int nextWidth = cur.second + dy[i];

			if (visited[nextLength][nextWidth]) continue;//방문여부
			if (node[nextLength][nextWidth] == 0) continue;//그려진여부
			if ((1 <= nextLength && nextLength <= n) &&
				(1 <= nextWidth && nextWidth <= m)) {//벽 조건
				q.push({ nextLength ,nextWidth });
				visited[nextLength][nextWidth] = true;
				drawCount++;
			}
		}
	}
	return drawCount;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;//세로,가로
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> node[i][j];
		}
	}

	int drawing = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && node[i][j] == 1) {
				drawMax = max(drawMax, bfs(i, j));
				drawing++;
			}
		}
	}
	cout << drawing << "\n" << drawMax;
}
