#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define INF 987654321

using namespace std;

int number = 0;
char board[26][26];
bool visited[26][26];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
priority_queue<int, vector<int>, greater<int>> pq;

void bfs(int x, int y, int n) {
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

			
			if (!(1 <= nextX && nextX <= n) || !(1 <= nextY && nextY <= n))
				continue;//범위가 아닐 경우

			if (board[nextX][nextY] == '1' && !visited[nextX][nextY]) {
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

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> board[i] + 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && board[i][j] == '1') {
				bfs(i, j, n);
			}
		}
	}

	cout << number << "\n";
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	return 0;
}