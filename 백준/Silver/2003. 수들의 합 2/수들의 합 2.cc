#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M = 0;
	cin >> N >> M;

	int answer = 0;
	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++) cin >> arr[i];

	int start = 0, end = 0;
	int sum = 0;
	while (end <= N) {
		if (sum < M) sum += arr[end++];
		else if (sum >= M) sum -= arr[start++];

		if (sum == M) answer++;
	}
	cout << answer;
}