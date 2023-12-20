#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0;
int w, h;
bool visited[51][51];
int map[51][51];

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void bfs(int a, int b) {
	queue<pair<int, int>> q;

	map[a][b] = 1;
	visited[a][b] = true;
	q.push({ a,b });

	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int NX = X + dx[i];
			int NY = Y + dy[i];
			
			if (!(0 <= NX && NX < h) || !(0 <= NY && NY < w)) continue;

			if (!visited[NX][NY] && map[NX][NY]) {
				visited[NX][NY] = true;
				q.push({ NX, NY });
			}
		}
	}
	answer++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		answer = 0;
		cin >> w >> h;
		if (!w && !h) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j]) {
					bfs(i, j);
				}
			}
		}

		for (int i = 0; i < h; i++) {//초기화
			for (int j = 0; j < w; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}