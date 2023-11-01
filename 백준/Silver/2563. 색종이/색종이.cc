#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	int board[101][101] = { 0, };

	int black = 10;
	for (int i = 0; i < n; i++) {
		int left, bottom;
		cin >> left >> bottom;

		for (int j = bottom; j < bottom + 10; j++) {
			for (int k = left; k < left + 10; k++) {
				board[j][k] = 1;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == 1) answer++;
		}
	}
	cout << answer;
}