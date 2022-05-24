#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	bool isBlack = false;

	int answer = 0;

	char board;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> board;
			if (!isBlack && board == 'F') answer++;
			isBlack = isBlack ? false : true;
		}
		isBlack = isBlack ? false : true;
	}
	cout << answer;
}