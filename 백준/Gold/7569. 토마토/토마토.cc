#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int m, n, h;
int board[101][101][101];
bool visited[101][101][101];
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0 ,0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

vector<int> v;
queue<pair<int, pair<int, int>>> q;

void bfs() {
	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second.first;
		int Z = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nX = X + dx[i];
			int nY = Y + dy[i];
			int nZ = Z + dz[i];
			if (!(0 <= nX && nX < m) ||
				!(0 <= nY && nY < n) ||
				!(0 <= nZ && nZ < h)) continue;
			if (!visited[nZ][nY][nX] && board[nZ][nY][nX] != -1) {
				q.push({ nX, {nY, nZ} });
				visited[nZ][nY][nX] = true;

				//항상 여기가 중요
				if(board[nZ][nY][nX] == 0) //0이면 그냥
					board[nZ][nY][nX] = board[Z][Y][X] + 1;
				else {//최소 익는 날 구하기
					if (board[nZ][nY][nX] > board[Z][Y][X] + 1)
						board[nZ][nY][nX] = board[Z][Y][X] + 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n >> h;//[h][n][m]hyx -> 가로 세로 높이
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[k][i][j];
				if (board[k][i][j] == 1) {
					q.push({ j, {i, k} });
					visited[k][i][j] = true;
					board[k][i][j] = 1;
				}
			}
		}
	}

	bfs();

	int max = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
				max = max < board[k][i][j] ? board[k][i][j] : max;
			}
		}
	}
	/*for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << board[k][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "-----------------\n";
	}*/

	cout << max - 1;
	return 0;
}
