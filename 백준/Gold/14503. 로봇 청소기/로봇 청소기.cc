#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 0 : 청소X / 1 : 벽 / 2 : 청소O
int board[50][50] = { 0, };
int cleaned[50][50] = { 0, };

//북동남서
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int N = 0, M = 0;
int x = 0, y = 0, dir = 0;
//0:북/1:동/2:남/3:서//

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//값 입력
	cin >> N >> M;// N:y // M:x
	cin >> y >> x >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int answer = 0;
	while (1) {
		bool allcleaned = true;

		if (board[y][x] == 0) {//청소
			board[y][x] = 2;
			answer++;
		}
		for (int i = 1; i <= 4; i++) {
			int tempDir = (dir - i + 4) % 4;//반시계방향
			int dirX = x + dx[tempDir];
			int dirY = y + dy[tempDir];
			
			//청소안한곳 찾으면
			if (board[dirY][dirX] == 0) {
				dir = tempDir;
				x = dirX;
				y = dirY;
				allcleaned = false;
				break;
			}
		}
		if (allcleaned) {
			int tempDir = (dir + 2) % 4;//뒷방향
			int dirX = x + dx[tempDir];
			int dirY = y + dy[tempDir];
			if (board[dirY][dirX] == 1) break;//뒤가 벽이면 작동X
			else if (board[dirY][dirX] == 2) {//뒤로 후진
				x = dirX;
				y = dirY;
			}
		}
	}

	cout << answer;
}
