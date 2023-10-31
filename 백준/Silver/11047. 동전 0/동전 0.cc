#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int answer = 0;
	int N, K;
	cin >> N >> K;

	int data[10] = { 0, };

	int coin = 0;
	for (int i = 0; i < N; i++) {
		cin >> coin;
		data[N - i - 1] = coin;
	}
	
	for (int i = 0; i < N; i++) {
		coin = data[i];
		if (1 <= K / coin) {

			answer += K / coin;
			K %= coin;

		}
	}
	cout << answer;
}