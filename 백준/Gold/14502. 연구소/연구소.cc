#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer = -1;
int board2[10][10];
int board[10][10];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;
vector<pair<int, int>> virus;

void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({ x, y });
	board[x][y] = 2;
	
	while (!q.empty()) {
		int vx = q.front().first;
		int vy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = vx + dx[i];
			int Y = vy + dy[i];
			if ((1 <= X && X <= n) && (1 <= Y && Y <= m)) {
				if (!board[X][Y]) {
					q.push({ X, Y });
					board[X][Y] = 2;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			board2[i][j] = board[i][j];

			if (board[i][j] == 2) virus.push_back({ i, j });
		}
	}

	for (int i = 0; i < n * m; i++) {
		if (board[i / m + 1][i % m + 1] != 0) continue;
		for (int j = i + 1; j < n * m; j++) {
			if (board[(j / m) + 1][j % m + 1] != 0) continue;
			for (int k = j + 1; k < n * m; k++) {
				if (board[(k / m) + 1][k % m + 1] != 0) continue;

				board[(i / m) + 1][i % m + 1] = 1;
				board[(j / m) + 1][j % m + 1] = 1;
				board[(k / m) + 1][k % m + 1] = 1;

				for (int i = 0; i < virus.size(); i++) {
					bfs(virus[i].first, virus[i].second);
				}

				int count = 0;
				for (int a = 1; a <= n; a++) {
					for (int b = 1; b <= m; b++) {
						if (!board[a][b]) count++;
					}
				}

				if (answer < count) {
					answer = count;
					//for (int a = 0; a <= 9; a++) {//초기화
					//	for (int b = 0; b <= 9; b++) {
					//		cout << board[a][b] << " ";
					//	}
					//	cout << "\n";
					//}
					//cout << answer << "\n==============\n";
				}
				for (int a = 1; a <= n; a++) {//초기화
					for (int b = 1; b <= m; b++) {
						board[a][b] = board2[a][b];
					}
				}
			}
		}
	}

	cout << answer;

	return 0;
}
