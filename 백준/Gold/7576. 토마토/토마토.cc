#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define INF 987654321

using namespace std;

int m, n;
int board[1001][1001];
bool visited[1001][1001];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void bfs() {

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (!(0 <= nextX && nextX < m) || !(0 <= nextY && nextY < n)) continue;
			if ((!visited[nextY][nextX]) && (board[nextY][nextX] != -1)) {

				q.push({ nextX, nextY });

				visited[nextY][nextX] = true;
				
				//여기가 중요포인트 익은토마토가 여러개 뿌려져있을 경우
				if (board[nextY][nextX] == 0)//
					board[nextY][nextX] = board[curY][curX] + 1;
				else {
					if (board[nextY][nextX] > board[curY][curX] + 1)
						board[nextY][nextX] = board[curY][curX] + 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n;
	
	int x, y;
	for (int i = 0; i < n; i++) {//값 입력
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {//익은 토마토 좌표 담기
				x = j;
				y = i;
				q.push({ x,  y });
				visited[y][x] = true;
				board[y][x] = 1;
			}
		}
	}

	bfs();

	int max = 0;
	for (int i = 0; i < n; i++) {//최대값
		for (int j = 0; j < m; j++) {
			if (!board[i][j]) {
				cout << -1;
				return 0;
			}
			max = max < board[i][j] ? board[i][j] : max;
		}
	}
	cout << max - 1;
	return 0;
}