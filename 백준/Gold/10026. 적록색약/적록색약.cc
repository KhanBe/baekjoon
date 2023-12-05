#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int answer1 = 0, answer2 = 0;
char board[101][101];
bool visited[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };

void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	char color = board[x][y];


	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (!(0 <= nextX && nextX < n) || !(0 <= nextY && nextY < n)) continue;
			if (!visited[nextX][nextY] && board[nextX][nextY] == color) {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
		}
	}
	answer1++;
}

void RG_bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	char color = board[x][y];


	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (!(0 <= nextX && nextX < n) || !(0 <= nextY && nextY < n)) continue;
			if (visited[nextX][nextY]) continue;
			if (board[nextX][nextY] == color) {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
			else if (board[nextX][nextY] == 'R' && color == 'G') {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
			else if (board[nextX][nextY] == 'G' && color == 'R') {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
		}
	}
	answer2++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	//---

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {//초기화
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				RG_bfs(i, j);
			}
		}
	}

	cout << answer1 << " " << answer2;
	

	return 0;
}
