#include <iostream>
#include <vector>

using namespace std;

int arr[50] = { 0, 1, 1, 2, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int answer = 0;
	int n = 0;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
		answer++;
	}

	cout << arr[n] << " " << answer;

	return 0;
}
