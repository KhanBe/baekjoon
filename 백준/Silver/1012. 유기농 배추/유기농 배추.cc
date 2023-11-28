#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define INF 987654321

using namespace std;

int number = 0;
int board[51][51];
bool visited[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
priority_queue<int, vector<int>, greater<int>> pq;

void bfs(int x, int y, int n, int m) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	int count = 1;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			
			if (!(1 <= nextX && nextX <= n) || !(1 <= nextY && nextY <= m))
				continue;//범위가 아닐 경우

			if (board[nextX][nextY] == 1 && !visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
				count++;
				q.push({ nextX, nextY });
			}
		}
	}

	pq.push(count);
	number++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int t;
	int n, m, k;
	cin >> t;


	for (int i = 0; i < t; i++) {//케이스별
		cin >> n >> m >> k;

		int x, y;
		for (int j = 0; j < k; j++) {//배추심기
			cin >> x >> y;
			board[x + 1][y + 1] = 1;
		}

		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= m; b++) {
				if (!visited[a][b] && board[a][b] == 1) {
					bfs(a, b, n, m);
				}
			}
		}

		for (int a = 0; a < 51; a++) {//배추심기 초기화
			for (int b = 0; b < 51; b++) {
				board[a][b] = 0;
				visited[a][b] = false;
			}
		}
		cout << number << "\n";
		number = 0;
	}

	return 0;
}