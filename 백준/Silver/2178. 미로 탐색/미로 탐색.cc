#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define INF 987654321

using namespace std;

int answer = INF;
int n = 0, m = 0;
char board[101][101];
bool visited[101][101];//dfs,bfs
int check[101][101];//bfs
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { -1, 0, 0, 1 };

void dfs(int x, int y, int move) {
	if (!(1 <= x && x <= m) || !(1 <= y && y <= n)) return;
	if (x == m && y == n) {
		answer = answer > move ? move : answer;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (board[nextY][nextX] == '1' && !visited[nextY][nextX]) {
			visited[nextY][nextX] = true;
			dfs(nextX, nextY, move + 1);
			visited[nextY][nextX] = false;
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;

	visited[y][x] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (!(1 <= nextX && nextX <= m) ||
				!(1 <= nextY && nextY <= n)) continue;

			if (board[nextY][nextX] == '1' && !visited[nextY][nextX]) {
				check[nextY][nextX] = check[y][x] + 1;
				visited[nextY][nextX] = true;
				q.push({ nextX, nextY });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//================================초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visited[i][j] = false;
			board[i][j] = '0';
			check[i][j] = 0;
		}
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> board[i] + 1;
	}

	//dfs(1, 1, 1);
	bfs(1, 1);

	//cout << answer;
	cout << check[n][m] + 1;
	return 0;
}