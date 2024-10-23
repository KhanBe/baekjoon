#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int board[16];
int answer = 0;

bool possible(int row) {
	for (int i = 0; i < row; i++) {
		// 같은 열이나 대각선 상에 퀸이 놓여있으면 false 
		if (board[row] == board[i] ||
			row - i == abs(board[row] - board[i])) {
			return false;
		}
	}
	return true;
}

void recursive(int row) {

	if (row == N) {
		answer++;
		return;
	}

	for (int column = 0; column < N; column++) {
		//(row, column)에 퀸 놓아보기
		board[row] = column;
		
		if (possible(row)) {
			recursive(row + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
		
	recursive(0);

	cout << answer;
	return 0;
}